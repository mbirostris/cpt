#ifndef cpt_second
#define cpt_second

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <limits>
#include <iomanip>
#include <algorithm>

#include "TChain.h"
#include "TEntryList.h"
#include "TMath.h"
#include "TFile.h"
#include "TLeaf.h"
#include "TString.h"
#include "TObjString.h"
#include "TROOT.h"
#include "TPluginManager.h"
#include "THStack.h"
#include "TCut.h"
#include "TArrayF.h"
#include "TStyle.h"
#include "TTree.h"
#include "TClassTable.h"
#include "TSystem.h"

#include "../interface/producer.h"

class second : public producer{


    virtual void produce(TTree* in, TTree* out, TTree* cut = 0) override{
    
    
    
        unsigned short paircount = 0;
        in->SetBranchAddress("paircount", &paircount);
        std::vector<float>* mupt = 0;
        in->SetBranchAddress("mupt", &mupt);
             

        unsigned short co = 0;
        out->Branch("cut",&co);

        unsigned short ci = 0;
        if(cut)
            cut->SetBranchAddress("cut",&ci);



        for (int i = 0; i < in->GetEntries(); i++) {
            in->GetEntry(i); out->GetEntry(i);
            if(cut)
                cut->GetEntry(i);

            unsigned short a = 0;
            unsigned short one = 1;
            for(std::vector<float>::iterator it = mupt->begin(); it != mupt->end(); ++it, one = one << 1){
                if (*it > 30)
                 a += one;
            }

            co = a;
            if(cut)
                co = co & ci;

 //           std::cout << "output: " << co << std::endl;
            out->Fill();
        }
        out->Write();
    
    }

};

#endif


