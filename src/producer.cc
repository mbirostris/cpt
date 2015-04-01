#include "../interface/producer.h"
#include "../interface/counter.h"

chain producer::get(chain ch){


    chain result = ch;
	for (std::vector<std::string >::size_type i = 0; i != ch.getSize(); i++){

		// czytamy oryginalny plik z drzewem
		TFile *file = new TFile((ch.getFolder(i)+ch.getFilename(i)).c_str());
		TTree *tree = (TTree*)file->Get(ch.getBranch(i).c_str());


		// robimy odpowiedni plik z selekcja
    //		f->GetListOfKeys()->Print();
		std::string outputFileName("./temp/");
		outputFileName += ch.getFilename(i);
		TFile *f = new TFile(outputFileName.c_str(),"UPDATE");


        std::string key = "0";
        while(f->GetKey(key.c_str())){
        
            int inn = rand() % 10000;
            key = std::to_string(inn);
        }
        result.setInn(key);


        //tree for new cut
        TTree *to = new TTree(result.getInn(),"");
    //    to->SetMakeClass(1); // Mowi, ze w branchu sa tylko typy podstawowe, jak float, int itp.

        TTree *cut = 0;
		if(f->GetKey(ch.getInn())){
            cut = (TTree*)f->Get(ch.getInn());
        }
        this->produce(tree, to, cut);

        delete to;
   //     f->Close();
        delete  f, file;

    }
    
    return result;

}
