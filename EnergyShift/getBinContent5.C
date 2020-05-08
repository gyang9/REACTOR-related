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

void getBinContent5()
{
      
      TFile * inputfile = new TFile("./outputFigs.root");

      TH1D* NEOS = (TH1D*)inputfile->Get("outPrediction[3]");
      NEOS->Draw();
      NEOS->Fit("pol9");
      TF1* func = NEOS->GetFunction("pol9"); 
      
      //cout<< func->GetParameter(0) <<endl;

      for(int i=1; i<31; i++){
	 cout<<0.25+i*0.25<<"~"<<0.5+i*0.25<<"\t"<<func->Eval(0.25+0.125+i*0.25)<<endl; 
      }

      TFile* outputFile = new TFile("newoutputFigs.root","RECREATE");
      TH1D * outPrediction = new TH1D("outPrediction[3]","title",30,0.5,8);
      TH1D * outPrediction_shifted = new TH1D("outPrediction_shifted[3]","title",30,0.5,8);	

      /*
      for(int i = 1; i<31; i++){
         outPrediction->SetBinContent(i,func->Eval(0.25+0.00125+i*0.0025));
      }
      */
      for(int i=1; i<=3324360; i++){
	 gRandom->SetSeed(i*1234);
         cout<< func->GetRandom() <<endl;
         outPrediction->Fill(func->GetRandom(),0.1);
	 outPrediction_shifted->Fill(1.048*func->GetRandom(),0.1);
      }

      outPrediction->Write();
      outPrediction_shifted->Write();
      outputFile->Close();
      
}

