#ifndef cpt_analyzer
#define cpt_analyzer

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <limits>
#include <iomanip>
#include <algorithm>


#include "../interface/chain.h"

class analyzer{


    virtual void analyze(TTree*,  TTree* ) = 0;


    public:

    void get(chain);



};

#endif


