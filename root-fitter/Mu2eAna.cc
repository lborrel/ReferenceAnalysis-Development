/*
Driving function for analysis
*/

#include <fstream>
#include<iostream>
#include "Mu2eAna.hh"

using namespace std;

void RunFit(){
  std::cout<<" TODO "<<std::endl;
}

int main(int argc, char* argv[]){
  std::cout<<"========== Welcome to Mu2eAna =========="<<std::endl;
  std::cout<<"-------- Analyzing "<<argv[1]<<"s ------------"<<std::endl;

  TString livetime = argv[1]; // in seconds
  RunFit();
  return 0;
}
