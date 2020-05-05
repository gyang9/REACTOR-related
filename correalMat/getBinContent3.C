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

void getBinContent3()
{
      TFile * inputfile = new TFile("./outputFigs.root");

      TH2D* NEOS = (TH2D*)inputfile->Get("outPrediction[3]");
  
      //Double array[NEOS->GetNbinsX()];

      for(Int_t i=0;i<NEOS->GetNbinsX();i++)
      {
 
              cout<<" i: "<<i<<" value:" << NEOS->GetBinContent(i)<<endl;
	      //array[i] = NEOS->GetBinContent(i);
      	      //gRandom->Gaus( (0.5+0.75)/2+i*0.25 , witdh=1sigma )   
      }

      



}

