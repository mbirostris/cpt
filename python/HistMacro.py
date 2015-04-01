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
 
def plot(variable, category, bins, HiggsMass): 
    
    folder = "./root/" + category + "/";
    bin_min = min(bins); bin_max = max(bins);
    bin_width=(bin_max-bin_min)/(len(bins)-1)
    bin_width2=[(bins[j+1]-bins[j])/2. for j in range(len(bins)-1)]
    #pliki
    pliki=["TTbar", "QCD", "WJets", "DY->ll, j->t", "Others", "DY->ll, l->t", "Embedded", "VH" + HiggsMass, "VBFH" + HiggsMass, "GGFH"+HiggsMass ]    
    
    
    X = np.array([bins[:-1],bins[1:]]).T.flatten()

    # reszta MC
    weighttable=[1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1];
    
    h = [];hw = [];
    for i in xrange(0, len(pliki)):
        try:
            h.append(root2rec(folder +pliki[i]+ '.root',variable)[variable]);
            hw.append(weighttable[i]*root2rec(folder+ pliki[i]+  '.root',variable)["weight"]);
        except:
            print "empty tree: " +  pliki[i]; 

    MChist = [];
    for i in range(0,len(h)):
        hist, bins = np.histogram(h[i], bins, weights=hw[i]);
        MChist.append(hist);
    
    
    #rysowanie
    fig = plt.figure(figsize=(16, 16)) 
    gs = gridspec.GridSpec(16, 1) 
    ax1 = plt.subplot(gs[0:12, :])
    
    #font = {'size'   : 28}
    #plt.rc('font', **font) #mozna zrobic globalny font
    
    legenda=[r'$t\bar{t}$', "QCD" , 'Electroweak', 'Electroweak', 'Electroweak', r'Z\to\mu\mu', r'$Z\to\tau\tau$ (embedded)' , r'(5x) H$\to\tau\tau$ $m_H = $'+HiggsMass , r'(5x) H$\to\tau\tau$ $m_H = $'+HiggsMass, r'(5x) H$\to\tau\tau$ $m_H = $'+HiggsMass ]
    kolor=["#7575FF","#FF80FF",       "#7A0000",  "#7A0000", "#7A0000",             "blue" ,                   "#FFD476"     , 'none',                         'none',            'none' ]
    kolors=['none',"#FF80FF",       "#7A0000",  "#7A0000", "#7A0000",             "blue" ,                   "#FFD476"     , "blue",                       "blue",            "blue" ]
    linie = ['-', '-', '-', '-','-','-','-', '--','--','--'];


    histsum = 0; Ymc = [];
    for i in range(0,len(MChist)):
        Ymc.append( np.array([MChist[i],MChist[i]]).T.flatten())
        histsum += MChist[i];

    rysunek = plt.stackplot(X, Ymc, colors=kolor, linestyle=linie, linewidths = None ,label='a') #plt.plot tez dzialaa
    
    counts, bins = np.histogram(root2rec(folder+'Data'+ '.root', variable)[variable], bins)
    dataERROR = np.sqrt(counts);
    plt.plot(bins[:-1] + bin_width2 , counts, 'bo', markersize=16 ,color='black', label='Observed' ,linestyle='None')
    plt.errorbar( bins[:-1] + bin_width2, counts,xerr=bin_width2, yerr=dataERROR, fmt='none')
    #rysunek[9].set_edgecolor('blue'); rysunek[9].set_linewidths(3);


    #legend
    handles, labels = plt.gca().get_legend_handles_labels()
    #print handles, labels
    #plt.legend([handles[0], handles[9], handles[7], handles[3], handles[2], handles[1] ], [labels[0], labels[9], labels[7], labels[3], labels[2], labels[1]])
    leg = plt.legend([handles[0],
        plt.Rectangle((0, 0), 1, 1, fc=kolor[0]), 
        plt.Rectangle((0, 0), 1, 1, fc=kolor[6]),
        plt.Rectangle((0, 0), 1, 1, fc=kolor[3]),
        plt.Rectangle((0, 0), 1, 1, fc=kolor[1]),
        plt.Rectangle((0, 0), 1, 1, fc=kolor[0])], 
        [labels[0],legenda[9], legenda[6], legenda[3], legenda[1], legenda[0]], numpoints=1, prop={'size':28})  #numpoints robi tylko jedna kropke w danych zamiast dwuch
    leg.draw_frame(False)
    plt.xlim([bin_min,bin_max]) #zaargumentowac to jar robimy debug
#    plt.ylim([0,max(counts) + 0.1*max(counts)])
    ax1.set_xlabel(variable + ' (GeV)', fontsize=28, position=(0.85,1))
    #ax1.set_xticks(bins[0::2])
    ax1.set_ylabel('Events/(' + str(bin_width) +' GeV)', fontsize=28, position=(1,0.85))
    
    #data do MC
    ax2  = plt.subplot(gs[14:, :])
    
    po = np.divide(np.array(counts-histsum, dtype=float), np.array(histsum, dtype=float))
    plt.plot(bins[:-1] + bin_width2, po, 'o', color='black', label='Efficiency', markersize=12)
    plt.axhline(y=0, linestyle='-', color='red', linewidth=3, zorder=2)
    plt.grid(True,which="both",ls="-", color='#808080') #grid
    ax2.set_ylabel(r'$\frac{{\mathrm{DATA - MC}}}{\mathrm{MC}}$', fontsize='21')
    #plt.ylim([-3.5,3.5])
    plt.xlim([bin_min,bin_max])
    #plt.draw()
    #plt.show()
    plt.close()
    return fig
    
