import sys 
import ROOT#gROOT, TCanvas, TF1, TFile
from root_numpy import root2array, root2rec, tree2rec
import os
import shutil
import math
from ROOT import * #gROOT, TCanvas, TF1, TFile
import pylab as pl
import numpy as np
import matplotlib.mlab as mlab
import matplotlib.pyplot as plt
from mpl_toolkits.axes_grid1 import host_subplot
import mpl_toolkits.axisartist as AA
from matplotlib import gridspec
from matplotlib.backends.backend_pdf import PdfPages
from array import array

gROOT.Reset() 
gROOT.SetBatch()

###########################################
#           datacards
###########################################


#category = ['0jet_low', '0jet_high', 'inclusive',  'boost_high', 'vbf'];
#category = [ 'inclusive', 'btag', 'btag_low', 'btag_high', 'nobtag'];
#category = ['nobtag_medium'];
'''
nazwa = ["data_obs", "TT", "ZTT", "W", "ZJ", "ZL", "ZLL", "VV", "QCD", "ggH125", "qqH125", "VH125"]


for j in range(0, len(category)):
    for i in range(0, len(nazwa)):
        c = TCanvas('blado', '_', 2400, 1800)

        plik=str("/home/dirack/Documents/CMS/tautau/historgramy/07/datacards/htt_mt.inputs-sm-8TeV.root");
        f = TFile(plik);
        t = f.Get("muTau_" + category[j]); 
        h = t.Get(nazwa[i]);
        
        plik1=str("/home/dirack/Documents/CMS/tautau/historgramy/07/tamplates/muTauSM_diTauNSVfitMass_newNames4_PtWeight.root");
        f1 = TFile(plik1);
        t1 = f1.Get("muTau_" + category[j])
        h1 = t1.Get(nazwa[i]);
        
        if nazwa[i] == 'QCD':
            h.Scale(1.)
'''
'''
        plik1=str("/home/dirack/Documents/CMS/tautau/datacards/muTau_mH125_vbf__diTauNSVfitMass.root");
        f1 = TFile(plik1);
        h1 = f1.Get("hSgn3");
'''
'''

        h.DrawCopy(); 
        h1.DrawCopy("same"); 

        c.Print("./comp/" + nazwa[i] + category[j]+ "_.png","png")
'''
variable = ['mupt', 'taupt', 'svfit','metsumEt']
prubka = "DYJetsToLL";

plik=str("/opt/CMMSW/tautau/cpt/trees/" + prubka + ".root");


for i in variable:
    c = TCanvas('blado', '_', 2400, 1800)
    gStyle.SetCanvasPreferGL(True)
#    runArray =  np.arange(0, 100, 10)
#    c.SetFillColor( 42 )
#    gStyle.SetFrameFillColor( 42 )
    f = TFile(plik);
    t = f.Get(i); 
    t.Draw(i);
#    gStyle.SetHistFillColor(34)

    c.Print("/opt/CMMSW/tautau/cpt/plots/" +prubka +'_'+ i + "_.png","png")
