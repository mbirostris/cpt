#ifndef cpt_print
#define cpt_print

#include <vector>

#include "../interface/analyzer.h"

class print : public analyzer{



    virtual void analyze(TTree* in, TTree* cut = 0) override{
    
//111111111-----------don't touch from here------------------------------------------------------------------------------   
        unsigned short ci = 0;
        if(cut)
            cut->SetBranchAddress("cut",&ci);
//111111111-----------don't touch to here------------------------------------------------------------------------------   
    


        // define variables
    
        std::vector<float> *mupt = 0;
        in->SetBranchAddress("mupt", &mupt);
        std::vector<float> *taupt = 0;
        in->SetBranchAddress("taupt", &taupt);
        std::vector<float> *svfit = 0;
        in->SetBranchAddress("svfit", &svfit);
        std::vector<float> *metpx = 0;
        in->SetBranchAddress("metpx", &metpx);
    


        for (int i = 0; i < in->GetEntries(); i++) {
//2222222222222-----------don't touch from here------------------------------------------------------------------------------   
            in->GetEntry(i); 
            if(cut){
                cut->GetEntry(i);
                if(!ci) continue;   
            }
//2222222222222-----------don't touch to here------------------------------------------------------------------------------   


            for (auto& i : *mupt)
                std::cout << " mupt: " << i;

            std::cout << " c: " << ci;
 /*           for (auto& i : *taupt)
                std::cout << " taupt: " << i;
            for (auto& i : *taupt)
                std::cout << " svfit: " << i;
            for (auto& i : *metpx)
                std::cout << " metpx: " << i;
*/
            std::cout << std::endl;
        }

    }
    

};

#endif


