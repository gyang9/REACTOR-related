/*
 *  t2k simple combined fit
 *
 *  Author: Guang Yang
 */
#include "simple_t2k.hh"
#include "TMath.h"

#include "RooArgList.h"
#include "RooAbsReal.h"
#include "RooAbsCategory.h"
#include "RooRealVar.h"
#include "RooAbsPdf.h"
#include "RooRealProxy.h"
#include <TVectorD.h>


  Sterile ::Sterile (const char* name) 
  : RooAbsReal(name,name)
{

// there will be: pull 0-2 s12, s23, s13, pull 3, CP delta, pull 4-6 dm2(21,32,31), pull 7-10 numu, nue Xsec and numu, nue selections

  _pulls     = new RooListProxy("_pulls","_pulls",this);
  RooRealVar* Par1 = new RooRealVar("s12","par1",TMath::ASin(TMath::Sqrt(0.85))/2.,0,100);
  RooRealVar* Par2 = new RooRealVar("s23","par2",TMath::ASin(TMath::Sqrt(0.95))/2.,0,100);
  RooRealVar* Par3 = new RooRealVar("s13","par3",TMath::ASin(TMath::Sqrt(0.1))/2.,0,100);
  RooRealVar* Par4 = new RooRealVar("delta","par4",-1.5,-10,10);
  RooRealVar* Par5 = new RooRealVar("dm21","par5",0.000075,-10,10);
  RooRealVar* Par6 = new RooRealVar("dm32","par6",0.00244,-10,10);
  RooRealVar* Par7 = new RooRealVar("dm31","par7",0.002365,-10,10);
  RooRealVar* Par8 = new RooRealVar("numuX","par8",1,0.,100);
  RooRealVar* Par9 = new RooRealVar("nueX","par9",1,0.,100);
  RooRealVar* Par10 = new RooRealVar("numuSel","par10",1,0.,100);
  RooRealVar* Par11 = new RooRealVar("nueSel","par11",1,0.,100);


Par1->setConstant(false);
Par2->setConstant(false);
Par3->setConstant(false);
Par4->setConstant(false);
Par5->setConstant(false);
Par6->setConstant(false);
Par7->setConstant(false);
Par8->setConstant(false);
Par9->setConstant(false);
Par10->setConstant(false);
Par11->setConstant(false);


_parlist.add(*Par1);
_parlist.add(*Par2);
_parlist.add(*Par3);
_parlist.add(*Par4);
_parlist.add(*Par5);
_parlist.add(*Par6);
_parlist.add(*Par7);
_parlist.add(*Par8);
_parlist.add(*Par9);
_parlist.add(*Par10);
_parlist.add(*Par11);
_pulls->add(_parlist);

  this->addServerList(*_pulls);

   };



  Sterile ::~Sterile ()
  {;}

TMatrixD* Sterile::prepareMatrix(TH2D* conv) const
{
Int_t nbin = conv->GetNbinsX();
TMatrixD* convMat = new TMatrixD(nbin,nbin);
Double_t sum[nbin];
    for(Int_t i=0;i<nbin;i++){
     for(Int_t j=0;j<nbin;j++){
       sum[i] += conv->GetBinContent(i,j);
                               }
                             }

    for(Int_t i=0;i<nbin;i++){
      for(Int_t j=0;j<nbin; j++){
        (*convMat)(i,j) = conv->GetBinContent(i,j)/sum[i];
                                }
                             }  

    return convMat;
}


TMatrixD* Sterile::prepareT2kCovMatrix(TMatrixD* covM_t2k, TVectorD* fVec_t2k) const
{
Int_t nbin = 30;
TMatrixD* covmatT2k = new TMatrixD(nbin,nbin);
    for(Int_t i=0;i<nbin;i++){
      for(Int_t j=0;j<nbin; j++){
        (*covmatT2k )(i,j) = (*covM_t2k)(i,j) * (*fVec_t2k)[i] * (*fVec_t2k)[j];
                                }
                             }  
    for(Int_t i=0;i<nbin;i++){
          (*covmatT2k )(i,i) += (*fVec_t2k)[i];                           
                             }
std::cout<<"t2k matrix sum "<<covmatT2k->Sum()<<std::endl;
return covmatT2k ;
}


TMatrixD* Sterile::prepareSkCovMatrix(TMatrixD* covM_sk, TVectorD* fVec_sk) const
{
Int_t nbin = 10;
TMatrixD* covmatSk = new TMatrixD(nbin,nbin);
    for(Int_t i=0;i<nbin;i++){
      for(Int_t j=0;j<nbin; j++){
        (*covmatSk )(i,j) = (*covM_sk)(i,j) * (*fVec_sk)[i] * (*fVec_sk)[j];
                                }
                             }  
return covmatSk ;
}

TMatrixD* Sterile::prepareJunoCovMatrix(Int_t nBins, TMatrixD* covM_JUNO, TVectorD* fVec_JUNO) const
{
Int_t nbin = nBins;
TMatrixD* covmatJUNO = new TMatrixD(nbin,nbin);
    for(Int_t i=0;i<nbin;i++){
      for(Int_t j=0;j<nbin; j++){
        (*covmatJUNO )(i,j) = (*covM_JUNO)(i,j) * (*fVec_JUNO)[i] * (*fVec_JUNO)[j];
                                }
                             }  
    for(Int_t i=0;i<nbin;i++){
          (*covmatJUNO )(i,i) += (*fVec_JUNO)[i];                           
                             }
//std::cout<<"JUNO matrix sum "<<covmatJUNO ->Sum()<<std::endl;
return covmatJUNO ;
}

Double_t Sterile::surv_JUNO(Double_t E, RooListProxy* _pulls) const
{
  Double_t delta_21 = ((RooAbsReal*)_pulls->at(4))->getVal()* E*1.27 ;
  Double_t delta_32 = ((RooAbsReal*)_pulls->at(5))->getVal()* E*1.27 ;
  Double_t delta_31 = ((RooAbsReal*)_pulls->at(6))->getVal()* E*1.27 ;

  Double_t prob = 1 -  TMath::Power(TMath::Sin( 2*((RooAbsReal*)_pulls->at(2))->getVal()),2) * ( TMath::Power(TMath::Cos(((RooAbsReal*)_pulls->at(0))->getVal()),2) *  TMath::Power(TMath::Sin(delta_31),2) +  TMath::Power(TMath::Sin(((RooAbsReal*)_pulls->at(0))->getVal()),2) * TMath::Power(TMath::Sin(delta_32),2) ) 
                    -  TMath::Power(TMath::Cos(((RooAbsReal*)_pulls->at(2))->getVal()),4) *  TMath::Power(TMath::Sin(2*((RooAbsReal*)_pulls->at(0))->getVal()),2) *  TMath::Power(TMath::Sin(delta_21),2);

    return prob;       
}

Double_t Sterile::surv_JUNO(Double_t E, TVectorD* parVec) const
{
  Double_t delta_21 = (*parVec)[4]* E*1.27 ;
  Double_t delta_32 = (*parVec)[5]* E*1.27 ;
  Double_t delta_31 = (*parVec)[6]* E*1.27 ;

  Double_t prob = 1 -  TMath::Power(TMath::Sin( 2*(*parVec)[2]),2) * ( TMath::Power(TMath::Cos((*parVec)[0]),2) * TMath::Power(TMath::Sin(delta_31),2) + TMath::Power(TMath::Sin((*parVec)[0]),2) * TMath::Power(TMath::Sin(delta_32),2) ) 
                    -  TMath::Power(TMath::Cos((*parVec)[2]),4) *  TMath::Power(TMath::Sin(2*(*parVec)[0]),2) *  TMath::Power(TMath::Sin(delta_21),2);

    return prob;       
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



Double_t Sterile ::FillEv( RooListProxy* _pulls ) const
{

   Int_t nBins = _Bins;
   Double_t junoSpec[nBins];

      //  [0 -> 750] ~ 6 years
      TF1* fnFunc = new TF1("fnFunc","[0]*exp(-0.5 * TMath::Power((x-[1])/[2],2))",0.,12.5);

      fnFunc->SetParameter(0,750);
      fnFunc->SetParameter(1,12.5);
      fnFunc->SetParameter(2,3);

      TF1* fnFunc2 = new TF1("fnFunc2","[0]*exp(-0.5 * TMath::Power((x-[1])/[2],2))",12.5,30.);

      fnFunc2->SetParameter(0,750);
      fnFunc2->SetParameter(1,12.5);
      fnFunc2->SetParameter(2,6);

         for(Int_t iBin=0; iBin<nBins*(12.5/30.); ++iBin) {
	Double_t content = fnFunc->Integral(iBin*12.5/(nBins*(12.5/30.)), (iBin+1)*12.5/(nBins*(12.5/30.)));
	junoSpec[iBin]=content;
      }
         for(Int_t iBin=0; iBin<nBins*(17.5/30.); ++iBin) {
        Int_t inBinNum = iBin+nBins*(12.5/30.);
	Double_t content = fnFunc->Integral(inBinNum *17.5/(nBins*(17.5/30.)), (inBinNum +1)*17.5/(nBins*(17.5/30.)));
	junoSpec[inBinNum]=content;
    //    std::cout<<inBinNum<<" "<<junoSpec[inBinNum]<<std::endl;
      }


   TMatrixD* covM_JUNO = new TMatrixD(nBins,nBins);
   for(Int_t i=0;i<nBins;i++){ (*covM_JUNO)(i,i) = 0.01*0.01; }

   Int_t nSpec = 1;
   TH1D* allVec[nSpec];
   allVec[0] = new TH1D("","",nBins,0.,30.);
   TVectorD* fVec_JUNO = new TVectorD(nBins);

   for(Int_t i=0;i<nBins;i++){   
         Double_t thisE = ((RooAbsReal*)_pulls->at(7))->getVal() * allVec[0]->GetBinCenter(i+1);
         (*fVec_JUNO)[i] = junoSpec[i] * this->surv_JUNO( thisE * 1000. , _pulls) ;
                        }
                           
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  TVectorD* dataIn = new TVectorD(11);
  (*dataIn )[0] = TMath::ASin(TMath::Sqrt(0.85))/2.;
  (*dataIn )[1] = TMath::ASin(TMath::Sqrt(0.95))/2.;
  (*dataIn )[2] = TMath::ASin(TMath::Sqrt(0.1))/2.;
  (*dataIn )[3] = -1.5;
  (*dataIn )[4] = 0.000075;
  (*dataIn )[5] = 0.00244;
  (*dataIn )[6] = 0.002515;
  (*dataIn )[7] = 1;
  (*dataIn )[8] = 1;
  (*dataIn )[9] = 1;
  (*dataIn )[10] = 1;

 //  std::cout<<"setting up data "<<std::endl;
   TVectorD* fData_t2k = new TVectorD(30);
   TVectorD* fData_sk = new TVectorD(10);
   TVectorD* fData_JUNO = new TVectorD(nBins);

   for(Int_t i=0;i<nBins;i++){ 
         Double_t thisE2 =  allVec[0]->GetBinCenter(i+1);
        (*fData_JUNO)[i] = junoSpec[i] * this->surv_JUNO(thisE2 * 1000. , dataIn )  ;  
              }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


   TMatrixD* covMatJUNO = this->prepareJunoCovMatrix(nBins ,covM_JUNO, fVec_JUNO);

 //  fVec_JUNO->Print();
 //  std::cout<<"Ok"<<std::endl;
 //  fData_JUNO->Print();
   
   for(Int_t i=0;i<nBins; i++){
       (*fVec_JUNO)[i] -= (*fData_JUNO)[i];
         if( (*covMatJUNO)(i,i) ==0 ){(*covMatJUNO)(i,i) = 1000000000;}
     }

   covMatJUNO->Invert();

   TVectorD mulVec(*fVec_JUNO);
   mulVec *= (*covMatJUNO);

   Double_t JunoResult = TMath::Abs(mulVec*(*fVec_JUNO));
   std::cout<<"chi2 sans pull "<<JunoResult<<std::endl;

   return (Double_t) JunoResult ; 
}


Double_t Sterile ::evaluate() const
{ 

Double_t matPart = this->FillEv(_pulls);

Double_t extraPull = this -> ExtraPull (_pulls);
Double_t tot = matPart + extraPull; //If needed, add pull terms here.

return tot;

}

Double_t Sterile ::ExtraPull (RooListProxy* _pulls) const
{
Double_t pullAdd = 0;
for(Int_t i=0;i<11;i++){
 pullAdd += TMath::Power(( ((RooAbsReal*)_pulls->at(i))->getVal() - (*pullCV)[i] ),2) / TMath::Power( (*pullUnc)[i],2) ;
    }
 std::cout<<"extra pull penalty: "<<pullAdd<<std::endl;
 return pullAdd;
}

Double_t Sterile ::getPar(int i) {
(((RooAbsReal*)_pulls->at(i))->getVal());
}

RooRealVar* Sterile ::getParVar(int i) {
return ((RooRealVar*)_pulls->at(i));
}

TVectorD* Sterile::getT2kVec() {
return fVec_t2k;
}

TVectorD* Sterile::getJunoVec() {
return fVec_JUNO;
}

TVectorD* Sterile::getSkVec() {
return fVec_sk;
}

void Sterile :: setSyst(Double_t syst){
_syst = syst;
}

void Sterile :: setdm2CV(Double_t dm2CV){
_dm2CV = dm2CV;
}

void Sterile :: setdm2Unc(Double_t dm2Unc){
_dm2Unc = dm2Unc;
}

void Sterile :: addSK(Bool_t wSK){
withSK = wSK;
}

void Sterile :: setAtmBaseline(Double_t AtmBaseline){
_AtmBaseline = AtmBaseline;
}

void Sterile :: setDensity(Double_t Density){
_Density = Density;
}

void Sterile :: setNBins(Double_t Bins){
_Bins= Bins;
}

void Sterile :: setTime(Double_t time){
_time = time ;
}

void Sterile :: setPull(TH1D* pullvecCV){
pullCV = new TVectorD(11);
for(Int_t i=0;i<11;i++){
(*pullCV)[i] =  pullvecCV->GetBinContent(i+1);
    }
}

void Sterile :: setPullUnc(TH1D* pullvecUnc){
pullUnc = new TVectorD(11);
for(Int_t i=0;i<11;i++){
(*pullUnc)[i] = pullvecUnc->GetBinContent(i+1);
    }
}

Double_t Sterile::getPullUnc(Int_t pN){
return (*pullUnc)[pN];
}

void Sterile::DataSwitch(Bool_t dataSwitch) const
{
Bool_t _dataSwitch = dataSwitch;
}

Bool_t Sterile::getDataSwitch() const
{
return _dataSwitch;
}

RooListProxy* Sterile::getPullList() const
{
return _pulls;
}

int main(int argc, char**argv){


RooFitResult* res;
Sterile * rep = new Sterile ("_rep");
  char formula[10];


rep->setAtmBaseline(0);
rep->setDensity(0);
TH1D* vecInput1 = new TH1D("","",11,0,11);
TH1D* vecInput2 = new TH1D("","",11,0,11);
//vecInput1->Print();

vecInput1 ->SetBinContent(1, TMath::ASin(TMath::Sqrt(0.85))/2.);
vecInput1 ->SetBinContent(2,TMath::ASin(TMath::Sqrt(0.95))/2.);
vecInput1 ->SetBinContent(3,TMath::ASin(TMath::Sqrt(0.1))/2.);
vecInput1 ->SetBinContent(4,-1.5);
vecInput1 ->SetBinContent(5,0.000075);
vecInput1 ->SetBinContent(6,0.00244);
vecInput1 ->SetBinContent(7,0.002365);
vecInput1 ->SetBinContent(8,1);
vecInput1 ->SetBinContent(9,1);
vecInput1 ->SetBinContent(10,1);
vecInput1 ->SetBinContent(11,1);

vecInput2 ->SetBinContent(1,TMath::ASin(TMath::Sqrt(0.85+0.021))/2.-TMath::ASin(TMath::Sqrt(0.85))/2.);
vecInput2 ->SetBinContent(2,2);
vecInput2 ->SetBinContent(3,TMath::ASin(TMath::Sqrt(0.1+0.005))/2.-TMath::ASin(TMath::Sqrt(0.1))/2.);
vecInput2 ->SetBinContent(4,2);
vecInput2 ->SetBinContent(5,0.0000018);
vecInput2 ->SetBinContent(6,0.00006);
vecInput2 ->SetBinContent(7,0.00006);
vecInput2 ->SetBinContent(8,0.0303);
vecInput2 ->SetBinContent(9,0.047);
vecInput2 ->SetBinContent(10,0.04); 
vecInput2 ->SetBinContent(11,0.027);

rep->setPull(vecInput1); 
rep->setPullUnc(vecInput2);
rep->addSK(true);

rep->setNBins(atof(argv[1]));
rep->FillEv(rep->getPullList());

RooArgList list("list");
list.add(*rep);
  sprintf(formula,"%s","@0");
RooFormulaVar* fcn = new RooFormulaVar("fit","fit",formula,list);


//rep->getParVar(3)->setVal(2.5);
//rep->getParVar(3)->setConstant(true);
//rep->getParVar(0)->setConstant(true);
//rep->getParVar(1)->setConstant(true);
//rep->getParVar(2)->setConstant(true);
//rep->getParVar(3)->setConstant(true);
//rep->getParVar(7)->setConstant(true);
//rep->getParVar(8)->setConstant(true);
//rep->getParVar(9)->setConstant(true);

RooMinuit m(*fcn);
m.setStrategy(2);
 Double_t callsEDM[2] = {10500., 1.e-6};
 Int_t irf = 0;

 gMinuit->mnexcm("MIGRAD",callsEDM,2,irf);
m.migrad();
//m.hesse();
//m.minos(); 
res = m.save();
double bestFit = res->minNll(); 

std::cout<<"result list: "<<std::endl;
std::cout<<"chi2: "<<bestFit <<std::endl;

for(Int_t i=0;i<11;i++){std::cout<<" "<<rep->getPar(i)<<std::endl;}

}
