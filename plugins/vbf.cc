#ifndef cpt_vbf
#define cpt_vbf


#include "../interface/producer.h"

class vbf : public producer{


    virtual void produce(TTree* in, TTree* out, TTree* cut = 0) override{
    
//--------------------D o   N O T   t o u c h   F R O M   h e r e------------------------------------------------/**/   
/**/        // output file cut branch                                                                            /**/   
/**/       unsigned short co = 0;                                                                                /**/
/**/       out->Branch("cut",&co);                                                                               /**/   
/**/       // cut                                                                                                /**/
/**/       unsigned short ci = 0;                                                                                /**/
/**/       if(cut)                                                                                               /**/
/**/           cut->SetBranchAddress("cut",&ci);                                                                 /**/
//--------------------D o   N O T   t o u c h    T O      h e r e------------------------------------------------/**/   



        // define variables
    /*
        unsigned short paircount = 0;
        in->SetBranchAddress("paircount", &paircount);
        std::vector<float> *vpx = 0;
        in->SetBranchAddress("vpx", &vpx);
   */       




        for (int i = 0; i < in->GetEntries(); i++) {
//--------------------D o   N O T   t o u c h   F R O M   h e r e------------------------------------------------/**/   
/**/       co = 0;
/**/       in->GetEntry(i); out->GetEntry(i); 
/**/       if(cut){
/**/           cut->GetEntry(i);
/**///           if(!ci) continue;    - tego nie moze byc, działa jak return w edmproducer => brak kolekcji
/**/       }
//--------------------D o   N O T   t o u c h    T O      h e r e------------------------------------------------/**/   



           /* do sth...
           unsigned short one = 1;
           for (auto& i : *vpx){
               if(i)
                   co += one;

               ...
               one = one << 1;
           }
           */



//--------------------D o   N O T   t o u c h   F R O M   h e r e------------------------------------------------/**/   
/**/        if(cut)
/**/            co = co & ci;
/**/       out->Fill();
/**/     }
/**/     out->Write();
/**/ }
//--------------------D o   N O T   t o u c h    T O      h e r e------------------------------------------------/**/   

    public:


};

#endif


