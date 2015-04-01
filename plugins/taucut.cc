#ifndef cpt_taucut
#define cpt_taucut


#include "../interface/producer.h"

class taucut : public producer{


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



        // define variables
    /*
        unsigned short paircount = 0;
        in->SetBranchAddress("paircount", &paircount);
   */       
        std::vector<float> *vpx = 0;
        in->SetBranchAddress("taupt", &vpx);
        std::vector<float> *vpx_ = 0;
        in->SetBranchAddress("mupt", &vpx_);




        for (int i = 0; i < in->GetEntries(); i++) {
//2222222222222-----------don't touch from here------------------------------------------------------------------------------   
            co = 0;
            in->GetEntry(i); out->GetEntry(i); 
            if(cut){
                cut->GetEntry(i);
            }
//2222222222222-----------don't touch to here------------------------------------------------------------------------------   



            unsigned short one = 1;
            for (auto& j : *vpx){
                if (j < 50)
                    co += one;           
                one = one << 1;
            }



//3333333333333-----------don't touch from here------------------------------------------------------------------------------   
            if(cut){
//                std::cout << "co: " << co << " ci: " << ci;
                co = co & ci;
                std::cout << " co: " << co;
            }
            out->Fill();

            one = 1;
            for (auto& j : *vpx_){
                if ( co & one)
                    std::cout << "--" << j << std::endl;;           
                one = one << 1;
            }

        }

        out->Write();
    
    }
//333333333333-----------don't touch to here------------------------------------------------------------------------------   


};

#endif


