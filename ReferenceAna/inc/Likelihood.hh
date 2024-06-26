#ifndef _Likelihood_hh
#define _Likelihood_hh


#include <fstream>
#include <iostream>
#include "TSystem.h"
#include "TROOT.h"
#include "TStyle.h"
#include "TFile.h"
#include "TH1.h"

#include "TF1.h"
#include "TMath.h"
#include "TTree.h"
#include "TCanvas.h"
#include "TPad.h"
#include "TMath.h"
#include <Riostream.h>

#include "TPaveStats.h"
#include "TPaveText.h"
#include "TLatex.h"
#include "TLegend.h"
#include "TPaveLabel.h"
#include "TAttFill.h"
// add roofit header files
#include "RooHist.h"
#include "RooRealVar.h"
#include "RooPlot.h"
#include "RooDataSet.h"
#include "RooDataHist.h"
#include "RooKeysPdf.h"
#include "RooHistPdf.h"
#include "RooGaussian.h"
#include "RooAddPdf.h"
#include "RooArgList.h"
#include "RooCBShape.h"
#include "RooGenericPdf.h"
#include "RooFFTConvPdf.h"
#include "RooFitResult.h"
#include "RooUniform.h"
#include "RooMinimizer.h"
#include "RooAbsReal.h"
//My stuff
#include "ReferenceAna/inc/RooPol58.hh"
#include "ReferenceAna/inc/RooDSCB.hh"
#include<tuple>
using namespace std;
using namespace TMath;
using namespace RooFit;
namespace rootfitter{
  class Likelihood  {
      public:
        explicit Likelihood(){};
        explicit Likelihood(const Likelihood &){};
        Likelihood& operator = (const Likelihood &);
        virtual ~Likelihood() = default;
        #ifndef __CINT__
        TString GetLabel(TString run);
        std::tuple <RooRealVar, RooRealVar, RooRealVar, RooRealVar>  CE_parameters();
        std::tuple <RooRealVar, RooRealVar, RooRealVar, RooRealVar>  DIO_parameters();
        std::tuple <RooRealVar, RooRealVar>  RPC_parameters();
        std::tuple <RooRealVar, RooRealVar, RooRealVar, RooRealVar,RooRealVar, RooRealVar> CE_DSCB();
        template <class T> void MakePlots(RooRealVar recomom, T chMom, RooAddPdf fitFun, TString tag, TString recocuts);
        RooFitResult *CalculateBinnedLikelihood(TH1F *hist_mom1, TString runname, bool usecuts, double mom_lo, double mom_hi, std::tuple <double, double, double, double>& recoresult);
        template <class T> RooFitResult *  MakeLikelihood(RooAddPdf &fitFun, T chMom, RooRealVar nsig, RooRealVar recomom);
        template <class T> RooFitResult *  MakeProfileLikelihood(RooAddPdf &fitFun, T chMom, RooRealVar nsig, RooRealVar recomom);
        double ReturnRmu(RooRealVar nsig, RooRealVar ndio);
        RooFitResult * CalculateUnbinnedLikelihood(TTree *mom, TString runname, bool usecuts, double mom_lo, double mom_hi,  std::tuple <double, double, double, double>& recoresult);
        #endif
        ClassDef (Likelihood,1);

    };
}
#endif /* Likelihood.hh */
