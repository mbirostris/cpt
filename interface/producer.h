#ifndef cpt_producer
#define cpt_producer

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

class producer{


    virtual void produce(TTree*, TTree*, TTree* ) = 0;


    public:

    chain get(chain);



};

#endif


