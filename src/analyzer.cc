#include "../interface/analyzer.h"
#include "../interface/counter.h"

void analyzer::get(chain ch){


	for (std::vector<std::string >::size_type i = 0; i != ch.getSize(); i++){


		// czytamy oryginalny plik z drzewem
		TFile *file = new TFile((ch.getFolder(i)+ch.getFilename(i)).c_str());
		TTree *tree = (TTree*)file->Get(ch.getBranch(i).c_str());


		// robimy odpowiedni plik z selekcja
    //		f->GetListOfKeys()->Print();
		std::string outputFileName("./temp/");
		outputFileName += ch.getFilename(i);
		TFile *f = new TFile(outputFileName.c_str());



        TTree *cut = 0;
		if(f->GetKey(ch.getInn())){
            cut = (TTree*)f->Get(ch.getInn());
        }
        this->analyze(tree, cut);

        delete  f, file;

    }
    

}
