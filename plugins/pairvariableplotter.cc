#ifndef cpt_pairvariableplotter
#define cpt_pairvariableplotter


#include "../interface/analyzer.h"

class pairvariableplotter : public analyzer{

    const char* variable_;
    std::string name_;
    float scaleFactor = 1;

    

    virtual void analyze(TTree* in, TTree* cut = 0) override{
    
    std::string outFileName = "./trees/" + name_;
    
    // file with result plot
    std::string ress(outFileName);
    ress+=".root"; 
    TFile *f = new TFile(ress.c_str(),"UPDATE");


    if(!( f->GetKey(variable_))){ // skip if plot already done for given file


        TTree *wynik = new TTree(variable_,"");
        float b;
        wynik->Branch(variable_, &b);

        std::vector<float> *vpx = 0;
        in->SetBranchAddress(variable_, &vpx);




        unsigned short ci = 0;
        if(cut)
            cut->SetBranchAddress("cut",&ci);

        for (int i = 0; i < in->GetEntries(); i++) {
            in->GetEntry(i); 
            if(cut){
                cut->GetEntry(i);
                // printing variable for first  in the event pair that passes
                unsigned short one = 1;
                for(float& j : *vpx ){
                    if (ci & one){
                        b=j;
                        wynik->Fill();
                        break;
                    }
                    one = one << 1;
                }
            }
            else{
                // printing variable of  first pair in the event only!
                for(float& j : *vpx ){
                    b=j;   
                    wynik->Fill();
                    break;
                }
            }



        }
        wynik->Write();
        delete wynik;

    }
    delete f;
    }
    
    public:

    pairvariableplotter(const char* variable, std::string name){
    
        variable_ = variable;
        name_ = name;
    }
    

};

#endif


