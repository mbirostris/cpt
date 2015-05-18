#include <iostream>
#include <dirent.h>
#include <stdio.h>
#include <cstdlib>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <limits>
#include <iomanip>
#include <initializer_list>
#include <array>
#include <regex>
#include <time.h>
#include <algorithm>


#include "../interface/chain.h"
#include "../interface/counter.h"
#include "../plugins/first.cc"
#include "../plugins/second.cc"
#include "../plugins/pairvariableplotter.cc"
#include "../plugins/print.cc"
//#include "../plugins/taucut.cc"
#include "../plugins/pairselector.cc"
#include "../plugins/pairvardrawer.cc"
#include "../plugins/synchronizer.cc"



using std::string; 
using std::cout; 
using std::endl; 
using std::vector;

    constexpr static float inf = std::numeric_limits<float>::max();

int main(int argc, const char *argv[]){


    std::string prubka = "ntuples";
    string folder = "/opt/CMMSW/Data/";
    string file = prubka+".root";
    string branch = "m2n/ntuple"; 

    gROOT->ProcessLine("#include <vector>");

    chain tt{{folder, file, branch}};
 //   std::cout << ttt.getInn() << std::endl;

//    first mucut;
//    chain tt1 = mucut.get(tt);
//    taucut tc;
//    chain tt2 = tc.get(tt1); 
    pairselector tauptcut("taupt", 0, 50);
    pairselector muptcut("mupt", 50, inf);
    pairselector svfitcut("svfit", 50, 150);

    chain inc = tauptcut.get(tt);
    inc = muptcut.get(inc);
    inc = svfitcut.get(inc);
    pairvardrawer p1("mupt", prubka + "mupt", TH1F("mupt", "mupt", 50, 0 ,200) ); 
    pairvardrawer p2("taupt", prubka + "taupt", TH1F("mupt", "mupt", 50, 0 ,200) ); 
    pairvardrawer p3("svfit", prubka + "svfitpt", TH1F("mupt", "mupt", 50, 0 ,200) ); 
//    pairvariableplotter p1("mupt", prubka);
//    pairvariableplotter p2("taupt", prubka);
//    pairvariableplotter p3("svfit", prubka);
//    pairvariableplotter p4("metpx", prubka);
//    pairvariableplotter p5("metpt", prubka);
//    pairvariableplotter p6("metphi", prubka);
//    pairvariableplotter p7("metsumEt", prubka);
    p1.get(inc); 
    p2.get(inc);
    p3.get(inc);
    std::cout << "integral: " << inc.integral();
//    p4.get(tt1);

    synchronizer a1("htt");
    a1.get(tt);
    
/*
    first h_;
    chain ch1 = h_.get(tt); 


    second hh_;
    chain ch2 = hh_.get(ch1); 

    pairvariableplotter p1("mupt", "mupt");
    pairvariableplotter p2("taupt", "mupt");
    p1.get(tt);
    p2.get(tt);
*/
//    print pr;
//    pr.get(tt);
//    pr.get(ch2);


    return 0;
}





