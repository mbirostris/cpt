#ifndef newtt_chain
#define newtt_chain

#include <iostream>
#include <dirent.h>
#include <stdio.h>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <limits>
#include <iomanip>
#include <cmath>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <boost/regex.hpp>
//#include <boost/xpressive/basic_regex.hpp>

#include "TChain.h"
#include "TCanvas.h"
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


class chain {

    std::string inn = "-1";
	typedef std::vector<std::string> Name; 
    Name folder, filename, branch;
    std::string selectionFolder, selectionFilename, selectionBranch;
	public:

	std::string getFolder(std::vector<std::string >::size_type) const;
	std::string getFilename(std::vector<std::string >::size_type) const;
	std::string getBranch(std::vector<std::string >::size_type) const;
	std::vector<std::string >::size_type getSize() const;
    struct Ch{std::string folder_ ;  std::string filename_ ; std::string branch_ ; };
    chain(std::initializer_list<Ch> l);
    void add(std::string folder_, std::string filename_, std::string branch_);
    chain(){}

    void put(std::string folder_, std::string filename_, std::string branch_);
	std::string getselectionFolder() const;
	std::string getselectionFilename() const;
	std::string getselectionBranch() const;


     const char* getInn() const {return inn.c_str();}
     void setInn(std::string s){this->inn = s;};
//    double integral(cut&, weight = empty, double scaleFactor = 1.); // TODO dodac defoultowa pusta selekcje
//    std::pair<double, double> intError(cut&, weight = empty, double scaleFactor = 1.); // TODO dodac defoultowa pusta selekcje
//    void plot(std::string, const char*, cut& , weight = empty, double scaleFactor = 1.);
//    void vplot(std::string, const char*, cut& , weight = empty, double scaleFactor = 1.);
	void print();

    int integral();

};

#endif
