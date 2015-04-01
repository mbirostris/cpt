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
import HistMacro as mac
import bins
from array import array
from subprocess import call


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
    

#category = ['0jet_low', '0jet_high', 'inclusive',  'boost_high', 'vbf']#'inclusive','boost_high', 'vbf']; # variable = ["MtLeg1MVA"]; bin_width = [1]; bin_min=[0]; bin_max=[150]
#category = ['inclusive', 'btag', 'btag_low', 'btag_high', 'nobtag']
category = [ 'nobtag_medium']

#variable = ["diTauNSVfitMass","diTauVisMass","visibleTauMass" ] #, "decayMode", "MEtMVA", "MEtMVAPhi", "MtLeg1MVA", "ptL1", "ptL2", "etaL1", "etaL2", "phiL1", "phiL2", "pt1", "pt2", "eta1", "eta2", "phi1", "phi2", "Deta", "Dphi", "Mjj", "diTauRecoPt", "numPV"];
variable = ["diTauNSVfitMass"];

for i in ['0jet_low']:
    call("hadd ./root/" +i+ "/QCD.root ./root/"+i+"/QCD_*.root", shell=True)

for i in ['btag','btag_low','btag_high','inclusive', 'nobtag', 'nobtag_low', 'nobtag_medium']:
    call("hadd ./root/" +i+ "/Embedded.root ./root/"+i+"/Data_Embedded.root ./root/"+i+"/TTbarEmb.root", shell=True)

#call(["hadd", "./root/inclusive/QCD.root", "./root/inclusive/QCD_Data.root", "./root/inclusive/QCD_DY->ll, j->t.root", "./root/inclusive/QCD_DY->ll, l->t.root", "./root/inclusive/QCD_DY->tautau.root", "./root/inclusive/QCD_DY->tt, jj.root", "./root/inclusive/QCD_LL.root", "./root/inclusive/QCD_Others.root", "./root/inclusive/QCD_TTbar.root", "./root/inclusive/QCD_WJets.root"])

HiggsMass = [];
for i in range(115,130,5):
    HiggsMass.append(str(i));

print "Proccesed Higgs Masses: ", HiggsMass;
pp = PdfPages('./plots/analysis.pdf')
for mass in HiggsMass:
    for j in xrange(0, len(category)):
        fih = page( category[j], mass)
        pp.savefig(fih)
        for i in xrange(0, len(variable)):
            if (category[j] == 'MtLeg1MVA' and variable[i] != 'MtLeg1MVA'):
                continue
            else:
                fig = mac.plot(variable[i], category[j], bins.get(category[j], variable[i]), mass)
            pp.savefig(fig)
            plt.close()

pp.close()

