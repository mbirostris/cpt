#ifndef cpt_inclusive
#define cpt_inclusive


#include "../interface/producer.h"

class inclusive : public producer{


    virtual void produce(TTree* in, TTree* out, TTree* cut = 0) override{
    
//111111111-----------don't touch from here------------------------------------------------------------------------------   
/**/        // output file cut branch                                                                               
/**/       unsigned short co = 0;
/**/       out->Branch("cut",&co);
/**/   
/**/       // cut
/**/       unsigned short ci = 0;
/**/       if(cut)
/**/           cut->SetBranchAddress("cut",&ci);
//111111111-----------don't touch to here------------------------------------------------------------------------------   



        // define variables
    /*
        unsigned short paircount = 0;
        in->SetBranchAddress("paircount", &paircount);
        std::vector<float> *vpx = 0;
        in->SetBranchAddress("vpx", &vpx);
   */       
        std::vector<float> *mucombreliso = 0;
        in->SetBranchAddress("mucombreliso", &mucombreliso);




        for (int i = 0; i < in->GetEntries(); i++) {
//2222222222222-----------don't touch from here------------------------------------------------------------------------------   
/**/           co = 0;
/**/           in->GetEntry(i); out->GetEntry(i); 
/**/           if(cut){
/**/               cut->GetEntry(i);
/**///               if(!ci) continue;    - tego nie moze byc, działa jak return w edmproducer => brak kolekcji
/**/           }
//2222222222222-----------don't touch to here------------------------------------------------------------------------------   



            unsigned short one = 1;
            for (auto& i : *mucombreliso){
                if(i < 0.1)
                    co += one;
                one = one << 1;
            }
            /* do sth...
            unsigned short one = 1;
            for (auto& i : *vpx){
                if(i)
                    co += one;

                ...
                one = one << 1;
            }
            */



//3333333333333-----------don't touch from here------------------------------------------------------------------------------   
/**/            if(cut)
/**/                co = co & ci;
/**/           out->Fill();
/**/       }
/**/
/**/       out->Write();
/**/   
/**/   }
//333333333333-----------don't touch to here------------------------------------------------------------------------------   

};

#endif


