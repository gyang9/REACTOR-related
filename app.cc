#include "simple_t2k.hh"
#include "TMath.h"

#include "RooArgList.h"
#include "RooAbsReal.h"
#include "RooAbsCategory.h"
#include "RooRealVar.h"
#include "RooAbsPdf.h"
#include "RooRealProxy.h"
#include "TString.h"
#include <TVectorD.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TFrame.h>

using namespace std;

 int main(int argc, char**argv){


 RooFitResult* res;
 Sterile * rep = new Sterile ("_rep");
   char formula[10];

 std::cout<<"start to run "<<std::endl;

 rep->setAtmBaseline(0);
 rep->setDensity(0);
 TH1D* vecInput1 = new TH1D("","",11,0,11);
 TH1D* vecInput2 = new TH1D("","",11,0,11);
 //vecInput1->Print();

 vecInput1 ->SetBinContent(1, TMath::ASin(TMath::Sqrt(0.85))/2.);
 vecInput1 ->SetBinContent(2,TMath::ASin(TMath::Sqrt(0.95))/2.);
 vecInput1 ->SetBinContent(3,0.1);
 vecInput1 ->SetBinContent(4,-1.5);
 vecInput1 ->SetBinContent(5,0.000075);
 vecInput1 ->SetBinContent(6,0.00238);
 vecInput1 ->SetBinContent(7,0.00244);
 vecInput1 ->SetBinContent(8,1);
 vecInput1 ->SetBinContent(9,1);
 vecInput1 ->SetBinContent(10,1);
 vecInput1 ->SetBinContent(11,1);

 vecInput2 ->SetBinContent(1,TMath::ASin(TMath::Sqrt(0.85+0.021))/2.-TMath::ASin(TMath::Sqrt(0.85))/2.);
 vecInput2 ->SetBinContent(2,2);
 vecInput2 ->SetBinContent(3,100);
 vecInput2 ->SetBinContent(4,2);
 vecInput2 ->SetBinContent(5,0.0000018);
 vecInput2 ->SetBinContent(6,0.0001);
 vecInput2 ->SetBinContent(7,0.00009);
 vecInput2 ->SetBinContent(8,0.009);
 vecInput2 ->SetBinContent(9,0.03);
 vecInput2 ->SetBinContent(10,0.04); 
 vecInput2 ->SetBinContent(11,0.027);

 std::cout<<"'ve set some inputs "<<std::endl;

 TH1D* binHist = new TH1D("","",34,0,34);
 for(Int_t i=0;i<34;i++){
   binHist->SetBinContent(i+1, 0.5 + 0.25*i);
 }

 TH1D* fissionHist = new TH1D("","",16,0,16);
 double fissionList[16]={0.49,0.09,0.35,0.07,    0.501,0.073,0.353,0.072,    0.679,0.072,0.215,0.035,      0.679,0.072,0.215,0.035};
 for(Int_t i=0;i<16;i++){
   fissionHist->SetBinContent(i+1, fissionList[i]);
 }

 rep->SetMatrixName("data/ReactorMatrixND_shape_rho0_NU.root");
 rep->SetBinning(binHist);
 rep->SetFissionFraction(fissionHist);

 std::cout<<"'ve set some more inputs "<<std::endl;

 rep->preparePrediction(rep->getPullList());
 rep->prepareData();

 rep->setPull(vecInput1); 
 rep->setPullUnc(vecInput2);
 rep->addSK(true);

 rep->setNBins(200);
 rep->setTime(6);

 std::cout<<"ended up with setting us basic stuff "<<std::endl;

 rep->FillEv(rep->getPullList());

 std::cout<<"'ve set some more & more inputs "<<std::endl;

 RooArgList list("list");
 list.add(*rep);
   sprintf(formula,"%s","@0");
 RooFormulaVar* fcn = new RooFormulaVar("fit","fit",formula,list);

 //rep->getParVar(3)->setVal(2.5);
 rep->getParVar(2)->setConstant(false);
 rep->getParVar(6)->setConstant(false);

 rep->getParVar(0)->setConstant(true);
 rep->getParVar(1)->setConstant(true);
 rep->getParVar(3)->setConstant(true);
 rep->getParVar(4)->setConstant(true);
 rep->getParVar(5)->setConstant(true);
 rep->getParVar(7)->setConstant(true);
 rep->getParVar(8)->setConstant(true);
 rep->getParVar(9)->setConstant(true);
 rep->getParVar(10)->setConstant(true);
 rep->getParVar(11)->setConstant(true);
 rep->getParVar(12)->setConstant(true);
 rep->getParVar(13)->setConstant(true);
 rep->getParVar(14)->setConstant(true);
 rep->getParVar(15)->setConstant(true);
 rep->getParVar(16)->setConstant(false);
 rep->getParVar(17)->setConstant(false);
 rep->getParVar(18)->setConstant(false);
 rep->getParVar(19)->setConstant(false);
 rep->getParVar(20)->setConstant(false);
 rep->getParVar(21)->setConstant(false);
 rep->getParVar(22)->setConstant(false);
 rep->getParVar(23)->setConstant(false);
 rep->getParVar(24)->setConstant(false);
 rep->getParVar(25)->setConstant(false);
 rep->getParVar(26)->setConstant(false);
 rep->getParVar(27)->setConstant(false);
 rep->getParVar(28)->setConstant(false);
 rep->getParVar(29)->setConstant(false);
 rep->getParVar(30)->setConstant(false);
 rep->getParVar(31)->setConstant(false);
 rep->getParVar(32)->setConstant(false);
 rep->getParVar(33)->setConstant(false);
 rep->getParVar(34)->setConstant(false);
 rep->getParVar(35)->setConstant(false);
 rep->getParVar(36)->setConstant(false);
 rep->getParVar(37)->setConstant(false);
 rep->getParVar(38)->setConstant(false);
 rep->getParVar(39)->setConstant(false);
 rep->getParVar(40)->setConstant(false);
 rep->getParVar(41)->setConstant(false);
 rep->getParVar(42)->setConstant(false);
 rep->getParVar(43)->setConstant(false);
 rep->getParVar(44)->setConstant(false);

 //    for(Int_t nn= 0; nn< npts ; ++nn) {

 //rep->setNBins(binSetup );
 //rep->setTime(atof(argv[5]));

 RooMinuit m(*fcn);
 m.setStrategy(2);
  Double_t callsEDM[2] = {10500., 1.e-6};
  Int_t irf = 0;

  gMinuit->mnexcm("MIGRAD",callsEDM,2,irf);
 m.migrad();
 //m.hesse();
 m.minos(); 
 res = m.save();
 double bestFit = res->minNll(); 

 std::cout<<"result list: "<<std::endl;
 std::cout<<"chi2: "<<bestFit <<std::endl;

   double bb =  rep->getParVar(2)->getAsymErrorLo();
   double dd =  rep->getParVar(2)->getAsymErrorHi();

 cout<<"errors are "<<bb<<" "<<dd<<endl;

 for(Int_t i=0;i<11;i++){std::cout<<" "<<rep->getPar(i)<<std::endl;}

   int aa = (atof(argv[5])+0.000001)*100;

   cout<<atoi(argv[2])<<" "<<aa<<" "<<dd<<endl; 

 //  }
 }
