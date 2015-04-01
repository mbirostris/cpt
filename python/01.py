import sys 
import os.path
import ROOT#gROOT, TCanvas, TF1, TFile
from root_numpy import root2array, root2rec, tree2rec
import os
import shutil
import math
from ROOT import * #gROOT, TCanvas, TF1, TFile


import numpy as np
import matplotlib.mlab as mlab
import matplotlib.pyplot as plt
from matplotlib import gridspec
from matplotlib.backends.backend_pdf import PdfPages
from array import array
from subprocess import call
import bins

import pylab as pl



gROOT.Reset() 
gROOT.SetBatch()
###########################################
#           control plots
###########################################
try:
    shutil.rmtree("./plots/")
except:
    print "OK..."

try:
    os.mkdir("./plots/")
except:
    print "Jedziemyyyy...."

def page(category, HiggsMass):
    fig = plt.figure(figsize=(16, 16))
    plt.axis([0, 10, 0, 10])
    plt.text(5, 7, "Kategoria:\n" + category + "\nHiggsMass: " + HiggsMass, fontsize=50,color='b', ha='center', va='top')
    return fig;


kolor=["#7575FF","#FF80FF",       "#7A0000",  "#7A0000", "#7A0000",             "blue" ,                   "#FFD476"     , 'none',                         'none',            'none' ]
linie = ['-', '-', '-', '-','-','-','-', '--','--','--'];

h = root2rec('./trees/wynik.root', 'mupt');

'''
def plot(variable, category = "", bins = np.arange(0, 100, 10) , HiggsMass = 125): 
    fig = plt.figure(figsize=(16, 10)) 
    gs = gridspec.GridSpec(16, 1) 
    ax1 = plt.subplot(gs[0:15, :])
    h = root2rec('./trees/wynik.root',variable)[variable];
    bin_min = min(bins); bin_max = max(bins);
    bin_width=(bin_max-bin_min)/(len(bins)-1)



    hist, bins = np.histogram(h, bins);

    Ymc = np.array( [hist , hist] ).T.flatten()
    X = np.array([bins[:-1],bins[1:]]).T.flatten()


    rysunek = plt.stackplot(X, Ymc, colors=kolor, linestyle=linie, linewidths = None ,label=variable) #plt.plot tez dzialaa
    ax1.set_xlabel(variable + ' [j]', fontsize=28, position=(0.85,1))
    #ax1.set_xticks(bins[0::2])
    ax1.set_ylabel('Events/(' + str(bin_width) +' [j])', fontsize=28, position=(1,0.85))

    #fig = plt.figure()
    plt.suptitle(variable, fontsize=26, fontweight='bold')

    #plt.plot(bins[:-1] + 10, hist)
    #plt.draw()
    #plt.show()
    return fig


####################################################################
variable = ['mupt', 'taupt', 'svfit','metsumEt']
###################################################################
pp = PdfPages('./plots/analysis.pdf')
for i in variable:
    fig = plot(i,"",  bins.get(i))
    pp.savefig(fig)
    plt.close() 

pp.close()

'''






