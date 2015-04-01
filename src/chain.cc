#include "../interface/chain.h"

//using namespace boost;

chain::chain(std::initializer_list<Ch> l){

for (auto x : l){
	boost::regex txt_regex(x.filename_);
	DIR *dir;
	struct dirent *ent;
	if ((dir = opendir (x.folder_.c_str())) != NULL) {
  		/* print all the files and directories within directory */
  		while ((ent = readdir (dir)) != NULL) {
			if(boost::regex_match(ent->d_name, txt_regex)){
				folder.push_back(x.folder_);
				filename.push_back(ent->d_name);
				branch.push_back(x.branch_);
//	    		printf ("%s\n", ent->d_name);
			}
  		}
  	closedir (dir);
	} else {
  		/* could not open directory */
 	 	perror ("-"); std::cout << x.folder_ << x.filename_; 
	}
}
}

void chain::add(std::string folder_, std::string filename_, std::string branch_){

    boost::regex txt_regex(filename_);
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir (folder_.c_str())) != NULL) {
        /* print all the files and directories within directory */
        while ((ent = readdir (dir)) != NULL) {
            if(boost::regex_match(ent->d_name, txt_regex)){
                folder.push_back(folder_);
                filename.push_back(ent->d_name);
                branch.push_back(branch_);
            }
        }
        closedir (dir);
     } else {
     /* could not open directory */
         perror ("-"); std::cout << folder_ << filename_;
     }
}

void chain::put(std::string folder_, std::string filename_, std::string branch_){

    selectionFolder = folder_;
    selectionFilename = filename_;
    selectionBranch = branch_;
}


void chain::print(){

    for (std::vector<std::string >::size_type i = 0; i != folder.size(); i++){
        std::cout << "Folder: " << folder[i] << "; Nazwa: " << filename[i] << "; Branch: " << branch[i] << std::endl; 
    }
}

std::vector<std::string >::size_type chain::getSize() const{

    return folder.size();
}


std::string chain::getFolder(std::vector<std::string >::size_type i) const{

    return folder[i];
}


std::string chain::getFilename(std::vector<std::string >::size_type i) const{

	return filename[i];
}


std::string chain::getBranch(std::vector<std::string >::size_type i) const{

	return branch[i];
}


std::string chain::getselectionFolder() const{

    return selectionFolder;
}


std::string chain::getselectionFilename() const{

	return selectionFilename;
}


std::string chain::getselectionBranch() const{

	return selectionBranch;
}



int chain::integral(){


    int result = 0;

	for (std::vector<std::string >::size_type i = 0; i != this->getSize(); i++){

		// czytamy oryginalny plik z drzewem
		TFile *file = new TFile((this->getFolder(i)+this->getFilename(i)).c_str());
		TTree *tree = (TTree*)file->Get(this->getBranch(i).c_str());


		// robimy odpowiedni plik z selekcja
    //		f->GetListOfKeys()->Print();
		std::string outputFileName("./temp/");
		outputFileName += this->getFilename(i);
        TFile *f = new TFile(outputFileName.c_str());



        TTree *cut = 0;
		if(f->GetKey(this->getInn())){
            cut = (TTree*)f->Get(this->getInn());
        }
        unsigned short ci = 0;
        if(cut)
            cut->SetBranchAddress("cut",&ci);

        for (int i = 0; i < tree->GetEntries(); i++) {
            tree->GetEntry(i); 
            if(cut){
                cut->GetEntry(i);
                if(!ci)
                    continue;
            }
            result++;
        }
        delete  f, file;
    }
    return result;
}


