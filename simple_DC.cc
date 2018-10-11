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
#include "TString.h"
#include <TVectorD.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TFrame.h>

using namespace std;

  Sterile ::Sterile (const char* name) 
  : RooAbsReal(name,name)
{

// there will be: pull 0-2 s12, s23, s13, pull 3, CP delta, pull 4-6 dm2(21,32,31), pull 7-10 numu, nue Xsec and numu, nue selections

  _pulls     = new RooListProxy("_pulls","_pulls",this);
  RooRealVar* Par1 = new RooRealVar("s12","par1",TMath::ASin(TMath::Sqrt(0.85))/2.,0,100);
  RooRealVar* Par2 = new RooRealVar("s23","par2",TMath::ASin(TMath::Sqrt(0.95))/2.,0,100);
  RooRealVar* Par3 = new RooRealVar("s14","par3",0.1,0,100);
  RooRealVar* Par4 = new RooRealVar("delta","par4",-1.5,-10,10);
  RooRealVar* Par5 = new RooRealVar("dm21","par5",0.000075,-10,10);
  RooRealVar* Par6 = new RooRealVar("dm32","par6",0.00238,-10,10);
  RooRealVar* Par7 = new RooRealVar("dm41","par7",0.00244,-10,10);
  RooRealVar* Par8 = new RooRealVar("numuX","par8",1,0.,100);
  RooRealVar* Par9 = new RooRealVar("nueX","par9",1,0.,100);
  RooRealVar* Par10 = new RooRealVar("numuSel","par10",1,0.,100);
  RooRealVar* Par11 = new RooRealVar("nueSel","par11",1,0.,100);

  RooRealVar* Par12 = new RooRealVar("reactorVar1","par12",1,-10,10) ;
  RooRealVar* Par13 = new RooRealVar("reactorVar2","par13",1,-10,10) ;
  RooRealVar* Par14 = new RooRealVar("reactorVar3","par14",1,-10,10) ;
  RooRealVar* Par15 = new RooRealVar("reactorVar4","par15",1,-10,10) ;
  RooRealVar* Par16 = new RooRealVar("reactorVar5","par16",1,-10,10) ;
  RooRealVar* Par17 = new RooRealVar("reactorVar6","par17",1,-10,10) ;
  RooRealVar* Par18 = new RooRealVar("reactorVar7","par18",1,-10,10) ;
  RooRealVar* Par19 = new RooRealVar("reactorVar8","par19",1,-10,10) ;
  RooRealVar* Par20 = new RooRealVar("reactorVar9","par20",1,-10,10) ;
  RooRealVar* Par21 = new RooRealVar("reactorVar10","par21",1,-10,10) ;
  RooRealVar* Par22 = new RooRealVar("reactorVar11","par22",1,-10,10) ;
  RooRealVar* Par23 = new RooRealVar("reactorVar12","par23",1,-10,10) ;
  RooRealVar* Par24 = new RooRealVar("reactorVar13","par24",1,-10,10) ;
  RooRealVar* Par25 = new RooRealVar("reactorVar14","par25",1,-10,10) ;
  RooRealVar* Par26 = new RooRealVar("reactorVar15","par26",1,-10,10) ;
  RooRealVar* Par27 = new RooRealVar("reactorVar16","par27",1,-10,10) ;
  RooRealVar* Par28 = new RooRealVar("reactorVar17","par28",1,-10,10) ;
  RooRealVar* Par29 = new RooRealVar("reactorVar18","par29",1,-10,10) ;
  RooRealVar* Par30 = new RooRealVar("reactorVar19","par30",1,-10,10) ;
  RooRealVar* Par31 = new RooRealVar("reactorVar20","par31",1,-10,10) ;
  RooRealVar* Par32 = new RooRealVar("reactorVar21","par32",1,-10,10) ;
  RooRealVar* Par33 = new RooRealVar("reactorVar22","par33",1,-10,10) ;
  RooRealVar* Par34 = new RooRealVar("reactorVar23","par34",1,-10,10) ;
  RooRealVar* Par35 = new RooRealVar("reactorVar24","par35",1,-10,10) ;
  RooRealVar* Par36 = new RooRealVar("reactorVar25","par36",1,-10,10) ;
  RooRealVar* Par37 = new RooRealVar("reactorVar26","par37",1,-10,10) ;
  RooRealVar* Par38 = new RooRealVar("reactorVar27","par38",1,-10,10) ;
  RooRealVar* Par39 = new RooRealVar("reactorVar28","par39",1,-10,10) ;
  RooRealVar* Par40 = new RooRealVar("reactorVar29","par40",1,-10,10) ;
  RooRealVar* Par41 = new RooRealVar("reactorVar30","par41",1,-10,10) ;
  RooRealVar* Par42 = new RooRealVar("reactorVar31","par42",1,-10,10) ;
  RooRealVar* Par43 = new RooRealVar("reactorVar32","par43",1,-10,10) ;
  RooRealVar* Par44 = new RooRealVar("reactorVar33","par44",1,-10,10) ;
  RooRealVar* Par45 = new RooRealVar("reactorVar34","par45",1,-10,10) ;


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
Par12->setConstant(false);
Par13->setConstant(false);
Par14->setConstant(false);
Par15->setConstant(false);
Par16->setConstant(false);
Par17->setConstant(false);
Par18->setConstant(false);
Par19->setConstant(false);
Par20->setConstant(false);
Par21->setConstant(false);
Par22->setConstant(false);
Par23->setConstant(false);
Par24->setConstant(false);
Par25->setConstant(false);
Par26->setConstant(false);
Par27->setConstant(false);
Par28->setConstant(false);
Par29->setConstant(false);
Par30->setConstant(false);
Par31->setConstant(false);
Par32->setConstant(false);
Par33->setConstant(false);
Par34->setConstant(false);
Par35->setConstant(false);
Par36->setConstant(false);
Par37->setConstant(false);
Par38->setConstant(false);
Par39->setConstant(false);
Par40->setConstant(false);
Par41->setConstant(false);
Par42->setConstant(false);
Par43->setConstant(false);
Par44->setConstant(false);
Par45->setConstant(false);


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
_parlist.add(*Par12);
_parlist.add(*Par13);
_parlist.add(*Par14);
_parlist.add(*Par15);
_parlist.add(*Par16);
_parlist.add(*Par17);
_parlist.add(*Par18);
_parlist.add(*Par19);
_parlist.add(*Par20);
_parlist.add(*Par21);
_parlist.add(*Par22);
_parlist.add(*Par23);
_parlist.add(*Par24);
_parlist.add(*Par25);
_parlist.add(*Par26);
_parlist.add(*Par27);
_parlist.add(*Par28);
_parlist.add(*Par29);
_parlist.add(*Par30);
_parlist.add(*Par31);
_parlist.add(*Par32);
_parlist.add(*Par33);
_parlist.add(*Par34);
_parlist.add(*Par35);
_parlist.add(*Par36);
_parlist.add(*Par37);
_parlist.add(*Par38);
_parlist.add(*Par39);
_parlist.add(*Par40);
_parlist.add(*Par41);
_parlist.add(*Par42);
_parlist.add(*Par43);
_parlist.add(*Par44);
_parlist.add(*Par45);
_pulls->add(_parlist);

this->addServerList(*_pulls);


  predDC = new TH1D("","predDC",34, 0.5, 8.);
  predDYB = new TH1D("","predDYB",34, 0.5, 8.);
  predRENO = new TH1D("","predRENO",34, 0.5, 8.);
  predNEOS = new TH1D("","predNEOS",34, 0.5, 8.);

  dataDC = new TH1D("","dataDC",34, 0.5, 8.);
  dataDYB = new TH1D("","dataDYB",34, 0.5, 8.);
  dataRENO = new TH1D("","dataRENO",34, 0.5, 8.);
  dataNEOS = new TH1D("","dataNEOS",34, 0.5, 8.);

};

Sterile ::~Sterile ()
{;}


TMatrixD* Sterile::prepareCovMatrix(Int_t nBins, TVectorD* fVec) const
{

  TFile fMatrixDC(fileNameDC);
  TFile fMatrixDYB(fileNameDYB);
  TFile fMatrixRENO(fileNameRENO);
  TFile fMatrixNEOS(fileNameNEOS);

  TMatrixD* fracMatDC = (TMatrixD*)fMatrixDC.Get("frac_approx");
  fracMatDC->ResizeTo(nBins,nBins);

  TMatrixD* fracMatDYB = (TMatrixD*)fMatrixDYB.Get("hCorrelation_0.25MeV");
  fracMatDYB->ResizeTo(nBins,nBins);

  TMatrixD* fracMatRENO = (TMatrixD*)fMatrixRENO.Get("hCorrelation_0.25MeV");
  fracMatRENO->ResizeTo(nBins,nBins);

  TMatrixD* fracMatNEOS = (TMatrixD*)fMatrixNEOS.Get("hCorrelation_0.25MeV");
  fracMatNEOS->ResizeTo(nBins,nBins);  
  
  // Reactor flux error vector from DYB paper : arXiv. 1607.05378
  double errlist_all[100]={0.042,0.03,0.025,0.022,0.021,0.019,0.017,0.015,0.015,0.0155,
	  		   0.017,0.018,0.02,0.022,0.025,0.029,0.033,0.035,0.037,0.041,
  			   0.052,0.065,0.072
  			  };
  double errlist_flux[100]={0.01,0.01,0.09,0.09,0.09,0.09,0.09,0.09,0.09,0.01,
	  		    0.01,0.01,0.01,0.011,0.013,0.014,0.015,0.016,0.018,
			    0.02,0.022,0.025  
  			   };
  TVectorD* errList = new TVectorD(nBins);
  for(Int_t i = 0; i< nBins; i++)
  {
      (*errList)[i] = errlist_all[i];
  }

  TMatrixD* outMat = new TMatrixD(4 * nBins , 4 * nBins);

  for(Int_t i = 0; i< nBins; i++)
  {
    for(Int_t j =0 ;j<nBins; j++) 
    { 
      //std::cout<<(*fracMat)(i,j)<<std::endl; 
        if((*fracMatDC)(4,4) > 0.5 )
            (*outMat)(i,j) = (*fracMatDC)(i,j) * (*errList)[i] * (*errList)[j] * (*fVec)[i] * (*fVec)[j];
	else      
	    (*outMat)(i,j) = (*fracMatDC)(i,j) * (*fVec)[i] * (*fVec)[j];
    }
  }

  for(Int_t i = nBins; i< 2 * nBins; i++)
  {
    for(Int_t j = nBins ;j< 2 *nBins; j++) 
    {
	if((*fracMatDYB)(nBins+4,nBins+4) > 0.5)
	    (*outMat)(i,j) = (*fracMatDYB)(i-nBins,j-nBins) * (*errList)[i-nBins] * (*errList)[j-nBins]  * (*fVec)[i] * (*fVec)[j];
	else
            (*outMat)(i,j) = (*fracMatDYB)(i-nBins,j-nBins) * (*fVec)[i] * (*fVec)[j];
    }
  }
  //std::cout<<"in middle of matrix preparation "<<std::endl;

  for(Int_t i = nBins+nBins; i<nBins*3; i++)
  {
    for(Int_t j = nBins+nBins ;j < nBins*3; j++) 
    {
	if((*fracMatRENO)(nBins + nBins+4, nBins + nBins+4) > 0.5)
	    (*outMat)(i,j) = (*fracMatRENO)(i-nBins-nBins,j-nBins-nBins) * (*errList)[i-nBins-nBins] * (*errList)[j-nBins-nBins]  * (*fVec)[i] * (*fVec)[j];		
	else
       	    (*outMat)(i,j) = (*fracMatRENO)(i-nBins-nBins,j-nBins-nBins) * (*fVec)[i] * (*fVec)[j];
    }
  }

  for(Int_t i = nBins*3; i< nBins*4; i++)
  {
    for(Int_t j = nBins*3 ;j< nBins*4; j++) 
    {
	if((*fracMatNEOS)(nBins + nBins + nBins+4, nBins + nBins + nBins+4) > 0.5)
            (*outMat)(i,j) = (*fracMatNEOS)(i-nBins-nBins-nBins,j-nBins-nBins-nBins) * (*errList)[i-nBins-nBins-nBins] * (*errList)[j-nBins-nBins-nBins]  * (*fVec)[i] * (*fVec)[j];
        else	    
      	    (*outMat)(i,j) = (*fracMatNEOS)(i-nBins-nBins-nBins,j-nBins-nBins-nBins) * (*fVec)[i] * (*fVec)[j];
    }
  }

  for(Int_t i = 0; i< nBins*4 ; i++)
  {
    (*outMat)(i,i) += (*fVec)[i] ;
    if((*outMat)(i,i) == 0) (*outMat)(i,i) += 0.0000000001;
  }

std::cout<<"matrix sum "<<outMat ->Sum()<<std::endl;
return outMat ;
}

Double_t Sterile::surv_Prob(Double_t E, RooListProxy* _pulls, Double_t L) const
{
  Double_t delta_21 = ((RooAbsReal*)_pulls->at(4))->getVal()* (L/E)*1.27 ;
  Double_t delta_32 = ((RooAbsReal*)_pulls->at(5))->getVal()* (L/E)*1.27 ;
  Double_t delta_31 = ((RooAbsReal*)_pulls->at(6))->getVal()* (L/E)*1.27 ;

  Double_t prob = 1 -  ((RooAbsReal*)_pulls->at(2))->getVal() *  TMath::Power(TMath::Sin(delta_31),2);

    return prob;       
}


Double_t Sterile ::FillEv( RooListProxy* _pulls ) const  
{

   int nBins = 34;

   std::vector<TH1D*> tempPredList = this->preparePrediction(_pulls);
   //std::cout<<"filled in new pediction "<<std::endl;
   //std::vector<TH1D*> tempDataList = this->prepareData();

   TVectorD* fVec = new TVectorD(nBins * 4);
   TVectorD* fData = new TVectorD(nBins * 4);

   TH1D* tempVec[4]; 
   TH1D* tempDat[4]; 
   for(Int_t i=0;i<4;i++){
     tempVec[i] = new TH1D("","",100,0,10);
     tempDat[i] = new TH1D("","",100,0,10);
   }

   for(Int_t i=0;i<nBins;i++){   
         Double_t thisE = (((RooAbsReal*)_pulls->at(8))->getVal()-1.) + ((RooAbsReal*)_pulls->at(7))->getVal() * predDC->GetBinCenter(i+1);
         (*fVec)[i]               = predDC->GetBinContent(i+1) * this->surv_Prob( (thisE) , _pulls, 400)  ;
	 (*fVec)[nBins + i]       = predDYB->GetBinContent(i+1) * this->surv_Prob( (thisE) , _pulls, 560)  ;
         (*fVec)[2 * nBins + i]   = predRENO->GetBinContent(i+1) * this->surv_Prob( (thisE) , _pulls, 410.6)  ;
         (*fVec)[3 * nBins + i]   = predNEOS->GetBinContent(i+1) * this->surv_Prob( (thisE) , _pulls, 20)  ;
         tempVec[0] -> SetBinContent(i+1, (*fVec)[i]);
	 tempVec[1] -> SetBinContent(i+1, (*fVec)[nBins + i]);
	 tempVec[2] -> SetBinContent(i+1, (*fVec)[2 * nBins + i]);
	 tempVec[3] -> SetBinContent(i+1, (*fVec)[3 * nBins + i]);
   }
   //std::cout<<"prepared new prediction"<<std::endl;
         
   for(Int_t i=0;i<nBins;i++){
	//std::cout<<dataDC->GetBinContent(i+1)<<" "<<dataDYB->GetBinContent(i+1)<<std::endl;
   	(*fData)[i]             = dataDC->GetBinContent(i+1)   ;
        (*fData)[nBins + i]     = dataDYB->GetBinContent(i+1)  ;
        (*fData)[2 * nBins + i] = dataRENO->GetBinContent(i+1) ;
        (*fData)[3 * nBins + i] = dataNEOS->GetBinContent(i+1) ;
        tempDat[0] -> SetBinContent(i+1, (*fData)[i]);
        tempDat[1] -> SetBinContent(i+1, (*fData)[nBins + i]);
        tempDat[2] -> SetBinContent(i+1, (*fData)[2 * nBins + i]);
        tempDat[3] -> SetBinContent(i+1, (*fData)[3 * nBins + i]);
   }
   //std::cout<<"data ready also "<<std::endl;
 
   double scaling1 = tempDat[0]->Integral() / tempVec[0]->Integral();
   double scaling2 = tempDat[1]->Integral() / tempVec[1]->Integral();
   double scaling3 = tempDat[2]->Integral() / tempVec[2]->Integral();
   double scaling4 = tempDat[3]->Integral() / tempVec[3]->Integral();

   for(Int_t i=0;i<nBins;i++){ 
        (*fData)[i]             = dataDC->GetBinContent(i+1)   - (*fVec)[i] * scaling1  ;
        (*fData)[nBins + i]     = dataDYB->GetBinContent(i+1)  - (*fVec)[nBins + i] * scaling2;
	(*fData)[2 * nBins + i] = dataRENO->GetBinContent(i+1) - (*fVec)[2 * nBins + i] * scaling3 ;
	(*fData)[3 * nBins + i] = dataNEOS->GetBinContent(i+1) - (*fVec)[3 * nBins + i] * scaling4;
   }
   std::cout<<"preparing matrix "<<std::endl;

   TMatrixD* covMat = this->prepareCovMatrix(nBins , fVec);

   covMat->Invert();

   TVectorD mulVec(*fData);
   mulVec *= (*covMat);

   Double_t currentResult = TMath::Abs(mulVec*(*fData));
   std::cout<<"chi2 sans pull "<<currentResult<<std::endl;

   return (Double_t) currentResult ; 
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


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


std::vector<TH1D*> Sterile:: preparePrediction(RooListProxy* _pulls) const
{

  TGraph* meuller235;
  TGraph* meuller238;
  TGraph* meuller239;
  TGraph* meuller241;

  if(modelList.at(0)=="data/mueller235.txt") 
	  meuller235 = new TGraph(modelList.at(0), "%lg %*lg %lg %*lg %*lg %*lg %*lg %*lg", "");
  else
	  meuller235 = new TGraph(modelList.at(0), "%lg %lg %*lg", "");

  if(modelList.at(1)=="data/mueller238.txt")
	  meuller238 = new TGraph(modelList.at(1), "%lg %lg %*lg %*lg %*lg", "");
  else
	  meuller238 = new TGraph(modelList.at(1), "%lg %lg %*lg", "");

  if(modelList.at(2)=="data/mueller239241.txt")
  	  meuller239 = new TGraph(modelList.at(2), "%lg %*lg %lg %*lg %*lg %*lg %*lg", "");
  else
	  meuller239 = new TGraph(modelList.at(2), "%lg %lg %*lg", "");

  if(modelList.at(3)=="data/mueller239241.txt")
  	  meuller241 = new TGraph(modelList.at(3), "%lg %*lg %*lg %*lg %*lg %lg %*lg", "");
  else
	  meuller241 = new TGraph(modelList.at(3), "%lg %lg %*lg", "");


  //TGraph* IBDXsec = new TGraph("data/IBDXsec.dat");
  TF1* IBDXsec = new TF1("IBDXsec","0.0952*(x-0.8)*( sqrt((x-0.8)*(x-0.8)-0.5*0.5))" ,1.8,10);

  double rateFactor = 1000;
  std::cout<<"entered into preparePrediction "<<std::endl;
  for(Int_t i=0;i<33;i++){
    if((binEdge[i]+binEdge[i+1])/2.>1.8){
    //std::cout<<"bin edge and fission fraction "<<i<<" "<<binEdge[i]<<" "<<fissionFraction[i]<<" "<<((RooAbsReal*)_pulls->at(i+12))->getVal()<<std::endl;
    //std::cout<<"fission rates: "<<meuller235->Eval((binEdge[i]+binEdge[i+1])/2.)<<" "<<meuller238->Eval((binEdge[i]+binEdge[i+1])/2.)<<" "<<meuller239->Eval((binEdge[i]+binEdge[i+1])/2.)<<" "<<meuller241->Eval((binEdge[i]+binEdge[i+1])/2.)<<std::endl;

      predDC -> SetBinContent( i+1,  IBDXsec->Eval((binEdge[i]+binEdge[i+1])/2.) *  rateFactor * (meuller235->Eval((binEdge[i]+binEdge[i+1])/2.) * fissionFraction[0] *  ((RooAbsReal*)_pulls->at(i+12))->getVal() + meuller238->Eval((binEdge[i]+binEdge[i+1])/2.) * fissionFraction[1] + meuller239->Eval((binEdge[i]+binEdge[i+1])/2.) * fissionFraction[2] + meuller241->Eval((binEdge[i]+binEdge[i+1])/2.) * fissionFraction[3] ));
     
      predDYB -> SetBinContent( i+1,  IBDXsec->Eval((binEdge[i]+binEdge[i+1])/2.) * rateFactor * (meuller235->Eval((binEdge[i]+binEdge[i+1])/2.) * fissionFraction[4] *  ((RooAbsReal*)_pulls->at(i+12))->getVal() + meuller238->Eval((binEdge[i]+binEdge[i+1])/2.) * fissionFraction[5] + meuller239->Eval((binEdge[i]+binEdge[i+1])/2.) * fissionFraction[6] + meuller241->Eval((binEdge[i]+binEdge[i+1])/2.) * fissionFraction[7] ));

      predRENO -> SetBinContent( i+1,  IBDXsec->Eval((binEdge[i]+binEdge[i+1])/2.) * rateFactor * (meuller235->Eval((binEdge[i]+binEdge[i+1])/2.) * fissionFraction[8] *  ((RooAbsReal*)_pulls->at(i+12))->getVal() + meuller238->Eval((binEdge[i]+binEdge[i+1])/2.) * fissionFraction[9] + meuller239->Eval((binEdge[i]+binEdge[i+1])/2.) * fissionFraction[10] + meuller241->Eval((binEdge[i]+binEdge[i+1])/2.) * fissionFraction[11] ));

      predNEOS -> SetBinContent( i+1,  IBDXsec->Eval((binEdge[i]+binEdge[i+1])/2.) * rateFactor * (meuller235->Eval((binEdge[i]+binEdge[i+1])/2.) * fissionFraction[12] *  ((RooAbsReal*)_pulls->at(i+12))->getVal() + meuller238->Eval((binEdge[i]+binEdge[i+1])/2.) * fissionFraction[13] + meuller239->Eval((binEdge[i]+binEdge[i+1])/2.) * fissionFraction[14] + meuller241->Eval((binEdge[i]+binEdge[i+1])/2.) * fissionFraction[15] ));
    }
  }

  std::cout<<"in the middle of preparePrediction "<<std::endl;
  std::vector<TH1D*> predictionList;
  predictionList.push_back(predDC);
  predictionList.push_back(predDYB);
  predictionList.push_back(predRENO);
  predictionList.push_back(predNEOS);

  return predictionList;
  
}

std::vector<TH1D*> Sterile:: prepareData() 
{

  TGraph* gradataDC   = new TGraph("data/dataDC.txt", "%*lg %lg %lg", "");
  TGraph* gradataDYB  = new TGraph("data/dataDYB.txt", "%*lg %lg %lg", "");
  TGraph* gradataRENO = new TGraph("data/dataRENO.txt", "%*lg %lg %lg", "");
  TGraph* gradataNEOS = new TGraph("data/dataNEOS.txt", "%*lg %lg %lg", "");

  for(Int_t i=0;i<predDC->GetNbinsX();i++)
  {
    dataDC -> SetBinContent(i+1, predDC->GetBinContent(i+1) * gradataDC->Eval(predDC->GetBinCenter(i+1)+0.78) );
    dataDYB -> SetBinContent(i+1,  predDYB->GetBinContent(i+1) * gradataDYB->Eval(predDYB->GetBinCenter(i+1)+0.78) );
    dataRENO -> SetBinContent(i+1,  predRENO->GetBinContent(i+1) * gradataRENO->Eval(predRENO->GetBinCenter(i+1)+0.78) );
    dataNEOS -> SetBinContent(i+1,  predNEOS->GetBinContent(i+1) * gradataNEOS->Eval(predNEOS->GetBinCenter(i+1)+0.78) );
  }

  std::vector<TH1D*> dataList;
  dataList.push_back(dataDC);
  dataList.push_back(dataDYB);
  dataList.push_back(dataRENO);
  dataList.push_back(dataNEOS);

  return dataList;

}


Double_t Sterile ::getPar(int i) {
(((RooAbsReal*)_pulls->at(i))->getVal());
}

RooRealVar* Sterile ::getParVar(int i) {
return ((RooRealVar*)_pulls->at(i));
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
_time= time;
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

void Sterile::SetBinning(TH1D* binHist)
{
for(Int_t i=0;i< binHist->GetNbinsX(); i++)
{
binEdge[i] = binHist->GetBinContent(i+1);
}
}

void Sterile::SetFissionFraction(TH1D* fissionHist)
{
for(Int_t i=0; i< fissionHist->GetNbinsX();i++)
fissionFraction[i] = fissionHist->GetBinContent(i+1);
}

void Sterile::SetMatrixNameDC(TString matrixName)
{
fileNameDC = matrixName;
}

void Sterile::SetMatrixNameDYB(TString matrixName)
{
fileNameDYB = matrixName;
}

void Sterile::SetMatrixNameNEOS(TString matrixName)
{
fileNameNEOS = matrixName;
}

void Sterile::SetMatrixNameRENO(TString matrixName)
{
fileNameRENO = matrixName;
}

void Sterile::SetModelList(std::vector<TString> mlist)
{
modelList = mlist;
}

std::vector<TH1D*> Sterile:: GetCurrentPrediction()
{
return this->preparePrediction(this->getPullList());
}

std::vector<TH1D*> Sterile:: GetCurrentData()
{
return this->prepareData();
}
