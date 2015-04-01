import sys
import os
import shutil
import math
import numpy as np
from array import array


def getold(category, variable):
    variable_ = ["diTauVisMass","diTauNSVfitMass","visibleTauMass", "decayMode", "MEtMVA", "MEtMVAPhi", "MtLeg1MVA", "ptL1", "ptL2", "etaL1", "etaL2", "phiL1", "phiL2", "pt1", "pt2", "eta1", "eta2", "phi1", "phi2", "Deta", "Dphi", "Mjj", "diTauRecoPt", "numPV"];
    bin_width = [10.0, 6.0, 0.1, 0.1, 4.0, 0.1, 2.0, 2.0,2.0, 0.1, 0.1, 0.1, 0.1,4.0 ,4.0, 0.4, 0.4, 0.4, 0.4, 0.4,0.4, 8.0,4.0,1.0];
    bin_min   = [0,   0,   0,   -0.1, 0,  -3.3, 0  , 0 , 0  ,-2.2,-2.2,-3.3,-3.3, 0  ,0  ,-6,-6,-5,-5,-2,0,             0 ,  0  ,0  ];
    bin_max   = [204, 356, 2.01, 2.3, 204, 3.3, 150 ,150,150, 2.2, 2.2, 3.3, 3.3,250,250, 7, 7, 5, 5, 9, 5,     500,  250,50 ];
    #bins=[0., 10.,  20., 30.,  40., 50.,  60., 70., 80.,90.,  100.,110., 120.,130., 140.,150., 160.,170., 180.,190., 200.,225., 250.,275., 300., 350. ];
    for i in range(0, len(variable_)):
        if ((category == 'vbf' or category == 'boost_high' or category == '0jet_low' or category == '0jet_high') and variable == 'diTauNSVfitMass'):
            bins = array('d', [0., 20., 40., 60., 80., 100., 120., 140., 160., 180., 200., 250., 300., 350. ]);
            break;
        if (variable_[i] == variable):
            bins=np.arange(bin_min[i],bin_max[i],bin_width[i]) 
    return bins;

def get(variable):
    variable_ = ['mupt', 'taupt', 'svfit','metsumEt']
    bin_width = [3.0, 2.0, 6, 20,     4.0, 0.1, 2.0, 2.0,2.0, 0.1, 0.1, 0.1, 0.1,4.0 ,4.0, 0.4, 0.4, 0.4, 0.4, 0.4,0.4, 8.0,4.0,1.0];
    bin_min   = [0,   0,   0, 200,     0,  -3.3, 0  , 0 , 0  ,-2.2,-2.2,-3.3,-3.3, 0  ,0  ,-6,-6,-5,-5,-2,0,             0 ,  0  ,0  ];
    bin_max   = [300, 200, 356, 2000, 204, 3.3, 150 ,150,150, 2.2, 2.2, 3.3, 3.3,250,250, 7, 7, 5, 5, 9, 5,     500,  250,50 ];
    #bins=[0., 10.,  20., 30.,  40., 50.,  60., 70., 80.,90.,  100.,110., 120.,130., 140.,150., 160.,170., 180.,190., 200.,225., 250.,275., 300., 350. ];
    for i in range(0, len(variable_)):
        if (variable_[i] == variable):
            bins=np.arange(bin_min[i],bin_max[i],bin_width[i]) 
    return bins;

