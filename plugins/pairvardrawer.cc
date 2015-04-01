#ifndef cpt_pairvardrawer
#define cpt_pairvardrawer


#include "../interface/analyzer.h"

class pairvardrawer : public analyzer{

    std::string variable;
    std::string name;
    float scaleFactor = 1;
    TH1F h;


    virtual void analyze(TTree* in, TTree* cut = 0) override{
    
//111111111-----------don't touch from here------------------------------------------------------------------------------   
/**/        unsigned short ci = 0;
/**/        if(cut)
/**/            cut->SetBranchAddress("cut",&ci);
//111111111-----------don't touch to here------------------------------------------------------------------------------   
    


        TCanvas c(variable.c_str(), "_", 2400, 1800);

        // define variables
        std::vector<float> *vpx = 0;
        in->SetBranchAddress(variable.c_str(), &vpx);
    

        for (int i = 0; i < in->GetEntries(); i++) {
//2222222222222-----------don't touch from here------------------------------------------------------------------------------   
/**/            in->GetEntry(i); 
/**/            if(cut){
/**/                cut->GetEntry(i);
/**/                if(!ci) continue;   
/**/            }
//2222222222222-----------don't touch to here------------------------------------------------------------------------------   


            if(cut){
                // printing variable for first  in the event pair that passes
                unsigned short one = 1;
                for(float& i : *vpx ){
                    if (ci & one){
                        h.Fill(i);
                        break;
                    }
                    one = one << 1;
                }
            }
            else{
                // printing variable of  first pair in the event only!
                for(float& i : *vpx ){
                    h.Fill(i);
                    break;
                }
            }
        }
        h.Draw();
        c.Modified();
        c.Update();
        std::string outFileName = "./plots/"  + name  + ".png";

        c.Print(outFileName.c_str(), "png");



    
    outFileName = "./trees/" + name;
    
    // file with result plot
    std::string ress(outFileName);
    ress+=".root"; 
    TFile *f = new TFile(ress.c_str(),"UPDATE");


    if(!( f->GetKey(variable.c_str()))){ // skip if plot already done for given file


        TTree *wynik = new TTree(variable.c_str(),"");
        float b;
        wynik->Branch(variable.c_str(), &b);

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

    pairvardrawer(std::string variable_, std::string name_, TH1F h_){
    
        variable = variable_;
        name = name_;
        h = h_;

    }
    
    

};

#endif


