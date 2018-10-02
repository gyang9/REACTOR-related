/*
 *  Sterile for NoVA header file.
 *
 *  Author: Guang Yang
 */

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <sstream>
#include <TList.h>

#include <TROOT.h>
#include <TCanvas.h>
#include <TApplication.h>
#include <TH1.h>
#include <TStyle.h>
#include <TSystem.h>
#include <TFile.h>
#include <TRint.h>
#include <TH2.h>
#include <TFormula.h>
#include <TF1.h>
#include <TF2.h>
#include <TMath.h>
#include <Math/DistFunc.h>
#include <TLine.h>
#include <TTree.h>
#include <TGraph.h>
#include <TRandom.h>
#include <TRandom3.h>
#include <TGraphErrors.h>
#include <TVirtualFFT.h>
#include <TFoamIntegrand.h>
#include <TMatrixD.h>
#include <TVectorT.h>
#include <TDecompChol.h>

#include <RooFit.h>
#include "RooGlobalFunc.h"
#include "RooAbsReal.h"
#include "RooAbsCategory.h"
#include "RooRealVar.h"
#include "RooAbsPdf.h"
#include "RooRealProxy.h"
#include "RooDataSet.h"
#include "RooArgList.h"
#include "RooArgSet.h"
#include "RooGaussian.h"
#include "RooProdPdf.h"
#include "RooWorkspace.h"
#include "RooMinuit.h"
#include "RooNLLVar.h"
#include "RooFitResult.h"
#include "RooPlot.h"
#include "RooDataSet.h"
#include "RooExtendPdf.h"
#include "RooChi2Var.h"
#include "RooMinuit.h"
#include "RooDataHist.h"
#include "RooHistPdf.h"
#include "RooRandom.h"
#include <RooMsgService.h>
#include <RooHist.h>
#include <RooTrace.h>
#include <RooCategory.h>
#include "RooConstVar.h"
#include "RooBinning.h"

#include "TStopwatch.h"
#include "TFile.h"
#include "TMinuit.h"

#include "RooFit.h"
#include "RooMinuit.h"
#include "RooFitResult.h"
#include "TMinuit.h"
#include <RooRealVar.h>

using namespace RooFit;


  class Sterile : public RooAbsReal {

  public:

    Sterile (const char* name);

    Sterile (const Sterile & other, const char* name = 0): RooAbsReal(other,name) {};
    virtual TObject* clone(const char* newname) const {return new Sterile (*this, newname);};
    virtual ~Sterile () ;

    Sterile (const Sterile & Sterile );

    void randomGo(int newIsotope, RooListProxy* _pulls);

    Sterile & operator=(const Sterile & rhs);

    RooFormulaVar* Chi2() ;

    Double_t FillEv(RooListProxy* _pulls) const ;

    Double_t ExtraPull(RooListProxy* _pulls) const;

    TMatrixD* prepareMatrix(TH2D* conv) const;
 
    void setSyst(Double_t syst) ;
    void setAtmBaseline(Double_t AtmBaseline) ;
    void setDensity(Double_t Density) ;

    void setNBins(Double_t Bins) ;
    void setTime(Double_t time) ;
    void setCorr1(Double_t Corr1) ;
    void setCorr2(Double_t Corr2) ;
    void setCorr3(Double_t Corr3) ;
    void setCorr4(Double_t Corr4) ;

    void setdm2CV(Double_t dm2CV) ;
    void setdm2Unc(Double_t dm2Unc) ;

    void setData(RooListProxy* _pulls) const;

    void setPull(TH1D* pullvecCV) ;
    void setPullUnc(TH1D* pullvecUnc) ;
    Double_t getPullUnc(Int_t pN) ;
    void addSK(Bool_t wSK) ;

    void SetBinning(TH1D* binHist) ;
    void SetFissionFraction(TH1D* fissionHist) ;
    void SetMatrixName(TString matrixName);
    void SetModelList(std::vector<TString>);

    TMatrixD* prepareCovMatrix(TH2D* conv, TVectorD* vec, Double_t syst) const;

    std::vector<TH1D*> prepareData() ;
    std::vector<TH1D*> preparePrediction(RooListProxy* _pulls) const;
    //std::vector<TH1D*> preparePrediction(RooListProxy* _pulls, std::vector<TString> modelList) const;

    TMatrixD* prepareT2kCovMatrix(TMatrixD* covM_t2k, TVectorD* fVec_t2k) const;
    TMatrixD* prepareT2kCovMatrix(TMatrixD* covM_t2k, TVectorD* fVec_t2k, Int_t nBins) const;
    TMatrixD* prepareT2kCovMatrixND(TMatrixD* covM_t2k, TVectorD* fVec_t2k, TVectorD* fVec_t2k_nd, Int_t nBins) const;
    TMatrixD* prepareSkCovMatrix(TMatrixD* covM_sk, TVectorD* fVec_sk) const;
    TMatrixD* prepareJunoCovMatrix(Int_t nBins, TMatrixD* covM_JUNO, TVectorD* fVec_JUNO) const;

    TMatrixD* prepareCovMatrix(Int_t nBins, TVectorD* fVec) const;

    RooRealVar Par1 ;
    RooRealVar Par2 ;
    RooRealVar Par3 ;
    RooRealVar Par4 ;
    RooRealVar Par5 ;
    RooRealVar Par6 ;
    RooRealVar Par7 ;
    RooRealVar Par8 ;
    RooRealVar Par9 ;
    RooRealVar Par10 ;
    RooRealVar Par11 ;
    RooRealVar Par12 ;
    RooRealVar Par13 ;
    RooRealVar Par14 ;
    RooRealVar Par15 ;
    RooRealVar Par16 ;
    RooRealVar Par17 ;
    RooRealVar Par18 ;
    RooRealVar Par19 ;
    RooRealVar Par20 ;
    RooRealVar Par21 ;
    RooRealVar Par22 ;
    RooRealVar Par23 ;
    RooRealVar Par24 ;
    RooRealVar Par25 ;
    RooRealVar Par26 ;
    RooRealVar Par27 ;
    RooRealVar Par28 ;
    RooRealVar Par29 ;
    RooRealVar Par30 ;
    RooRealVar Par31 ;
    RooRealVar Par32 ;
    RooRealVar Par33 ;
    RooRealVar Par34 ;
    RooRealVar Par35 ;
    RooRealVar Par36 ;
    RooRealVar Par37 ;
    RooRealVar Par38 ;
    RooRealVar Par39 ;
    RooRealVar Par40 ;
    RooRealVar Par41 ;
    RooRealVar Par42 ;
    RooRealVar Par43 ;
    RooRealVar Par44 ;
    RooRealVar Par45 ;
    RooRealVar Par46 ;
    RooRealVar Par47 ;
    RooRealVar Par48 ;
    RooRealVar Par49 ;
    RooRealVar Par50 ;
    RooRealVar Par51 ;
    RooRealVar Par52 ;
    RooRealVar Par53 ;
    RooRealVar Par54 ;
    RooRealVar Par55 ;
    RooRealVar Par56 ;
    RooRealVar Par57 ;
    RooRealVar Par58 ;
    RooRealVar Par59 ;
    RooRealVar Par60 ;

    Double_t _par1;
    Double_t _par2;
    Double_t _par3;
    Double_t _par4;
    Double_t _par5;
    Double_t _par6;
    Double_t _par7;
    Double_t _par8;
    Double_t _par9;
    Double_t _par10;
    Double_t _par11;
    Double_t _par12;
    Double_t _par13;
    Double_t _par14;
    Double_t _par15;
    Double_t _par16;
    Double_t _par17;
    Double_t _par18;
    Double_t _par19;
    Double_t _par20;
    Double_t _par21;
    Double_t _par22;
    Double_t _par23;
    Double_t _par24;
    Double_t _par25;
    Double_t _par26;
    Double_t _par27;
    Double_t _par28;
    Double_t _par29;
    Double_t _par30;
    Double_t _par31;
    Double_t _par32;
    Double_t _par33;
    Double_t _par34;
    Double_t _par35;
    Double_t _par36;
    Double_t _par37;
    Double_t _par38;
    Double_t _par39;
    Double_t _par40;
    Double_t _par41;
    Double_t _par42;
    Double_t _par43;
    Double_t _par44;
    Double_t _par45;
    Double_t _par46;
    Double_t _par47;
    Double_t _par48;
    Double_t _par49;
    Double_t _par50;
    Double_t _par51;
    Double_t _par52;
    Double_t _par53;
    Double_t _par54;
    Double_t _par55;
    Double_t _par56;
    Double_t _par57;
    Double_t _par58;
    Double_t _par59;
    Double_t _par60;

    Double_t getPar(int i) ;
    void DataSwitch(Bool_t dataSwitch=true) const;
    Bool_t getDataSwitch() const;

    Double_t surv_t2k(Double_t L, Double_t E, RooListProxy* _pulls) const ;
    Double_t app_t2k(Double_t L, Double_t E, Double_t density, RooListProxy* _pulls) const ;
    Double_t survNue_sk(Double_t L, Double_t E, Double_t density, RooListProxy* _pulls) const ;
    Double_t survNumu_sk(Double_t L, Double_t E, RooListProxy* _pulls) const ;

    Double_t surv_t2k(Double_t L, Double_t E, TVectorD* parVec) const ;
    Double_t app_t2k(Double_t L, Double_t E, Double_t density, TVectorD* parVec) const ;
    Double_t survNue_sk(Double_t L, Double_t E, Double_t density, TVectorD* parVec) const ;
    Double_t survNumu_sk(Double_t L, Double_t E, TVectorD* parVec) const ;

    Double_t surv_JUNO(Double_t E, RooListProxy* _pulls) const ;
    Double_t surv_JUNO(Double_t E, TVectorD* parVec) const ;

    Double_t surv_JUNO(Double_t E, RooListProxy* _pulls, Double_t L) const ;
    Double_t surv_JUNO(Double_t E, TVectorD* parVec, Double_t L) const ;

    Double_t surv_Prob(Double_t E, RooListProxy* _pulls, Double_t L) const ;

    RooRealVar* getParVar(int i) ;
    RooListProxy* getParVar() ;
    RooListProxy* getPullList() const;

    TVectorD* getSkVec() ;
    TVectorD* getT2kVec() ;
    TVectorD* getJunoVec() ;
    TVectorD* getJunoData() ;

    TH1D* getJunoHist() ;
    TH1D* getJunoDataHist() ;

    RooArgList _parlist;
    RooListProxy* _pulls;

    std::vector<TH1D*> GetCurrentPrediction();
    std::vector<TH1D*> GetCurrentData();

   TH2D* conv;
   TH1D* nueAfter;
   TH1D* nueBefore;
   TH1D* numuTrue;

   Double_t _syst;
   Double_t _dm2CV;
   Double_t _dm2Unc;

   Double_t _Density;
   Double_t _AtmBaseline;
   Double_t _time;
   Double_t _Bins;
   Double_t _Corr1;
   Double_t _Corr2;
   Double_t _Corr3;
   Double_t _Corr4;
   Double_t dataSet;
   Bool_t _dataSwitch;

   TVectorD* pullCV; 
   TVectorD* pullUnc;
   TVectorD* fData_t2k;
   TVectorD* fData_sk;
   TVectorD* fData_JUNO;

   TVectorD* fVec_t2k;
   TVectorD* fVec_t2k_nd;
   TVectorD* fVec_sk;
   TVectorD* fVec_JUNO;
   TVectorD* fVecShadow_JUNO;

   TVectorD* MCDelegate;
   TVectorD* dataDelegate;

   TH1D* hData_JUNO;
   TH1D* hShadow_JUNO;
   
   Bool_t withSK ;

   TString fileName;
   double fissionFraction[100];
   double binEdge[100];

   TH1D* dataDC;
   TH1D* dataDYB;
   TH1D* dataRENO;
   TH1D* dataNEOS;
   TH1D* predDC;
   TH1D* predDYB;
   TH1D* predRENO;
   TH1D* predNEOS;

   std::vector<TString> modelList;

   std::vector<TH1D*> dataList;

    //  private:
   
  virtual  Double_t evaluate() const ;

  protected:


  };


