#ifndef cpt_first
#define cpt_first

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

class first : public producer{


    virtual void produce(TTree* in, TTree* out, TTree* cut = 0) override{
    
    
//111111111-----------don't touch from here------------------------------------------------------------------------------   
        // output file cut branch
        unsigned short co = 0;
        out->Branch("cut",&co);
    
        // cut
        unsigned short ci = 0;
        if(cut)
            cut->SetBranchAddress("cut",&ci);
//111111111-----------don't touch to here------------------------------------------------------------------------------   
    
        unsigned short paircount = 0;
        in->SetBranchAddress("paircount", &paircount);
        std::vector<float>* mupt = 0;
        in->SetBranchAddress("mupt", &mupt);
             



        for (int i = 0; i < in->GetEntries(); i++) {
//2222222222222-----------don't touch from here------------------------------------------------------------------------------   
            co = 0;
            in->GetEntry(i); out->GetEntry(i); 
            if(cut){
                cut->GetEntry(i);
            }
//2222222222222-----------don't touch to here------------------------------------------------------------------------------   


            unsigned short one = 1;
            for(auto& i : *mupt){
                if (i < 50 )
                    co += one;
                one = one << 1;
            }


/*
            if(paircount == 2)
                co = paircount;
            else
                co = 0;
*/
//3333333333333-----------don't touch from here------------------------------------------------------------------------------   
            if(cut)
                co = co & ci;
            out->Fill();
        }

        out->Write();
    
    }
//333333333333-----------don't touch to here------------------------------------------------------------------------------   


};

#endif


