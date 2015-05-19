#ifndef cpt_synchronizer
#define cpt_synchronizer


#include "../interface/analyzer.h"

class synchronizer : public analyzer{


    std::string name;

    virtual void analyze(TTree* in, TTree* cut = 0) override{
 

        std::string outFileName = "./trees/" + name;
        std::string ress(outFileName);
        ress+=".root"; 
        TFile *f = new TFile(ress.c_str(),"UPDATE");

        if(!( f->GetKey(name.c_str()))){ // skip if plot already done for given file
            
            TTree *synchtree = new TTree(name.c_str(),"");
            float run = 0; synchtree->Branch("run", &run);
            float lumi = 0; synchtree->Branch("lumi", &lumi);
            float evt = 0;  synchtree->Branch("evt", &evt);

            float isZtt = 0; synchtree->Branch("isZtt", &isZtt);
            float isZmt = 0; synchtree->Branch("isZmt", &isZmt);
            float isZet = 0; synchtree->Branch("isZet", &isZet);
            float isZee = 0; synchtree->Branch("isZee", &isZee);
            float isZmm = 0; synchtree->Branch("isZmm", &isZmm);
            float isZem = 0; synchtree->Branch("isZem", &isZem);
            float isZEE = 0; synchtree->Branch("isZEE", &isZEE);
            float isZMM = 0; synchtree->Branch("isZMM", &isZMM);
            float isZLL = 0; synchtree->Branch("isZLL", &isZLL);
            float isFake = 0; synchtree->Branch("isFake", &isFake);
            float NUP = 0; synchtree->Branch("NUP", &NUP);  //nup

            float weight = 0; synchtree->Branch("weight", &weight);
            float puweight = 0; synchtree->Branch("puweight", &puweight);

            float npv = 0; synchtree->Branch("npv", &npv); //npv
            float npu = 0; synchtree->Branch("npu", &npu); //npu
            float rho = 0; synchtree->Branch("rho", &rho); 

            //Leg 1 (leading tau for tt, tau for et, mt, muon for em) 
            float pt_1 = 0; synchtree->Branch("pt_1", &pt_1); //mupt
            float phi_1 = 0; synchtree->Branch("phi_1", &phi_1); //muphi
            float eta_1 = 0; synchtree->Branch("eta_1", &eta_1); //mueta
            float m_1 = 0; synchtree->Branch("m_1", &m_1); //mum
            float q_1 = 0; synchtree->Branch("q_1", &q_1); //muq
            float d0_1 = 0; synchtree->Branch("d0_1", &d0_1); // mud0
            float dZ_1 = 0; synchtree->Branch("dZ_1", &dZ_1); // mudz
            float mt_1 = 0; synchtree->Branch("mt_1", &mt_1); // mumt
            float iso_1 = 0; synchtree->Branch("iso_1", &iso_1); //mucombreliso
            float id_m_loose_1 = 0; synchtree->Branch("id_m_loose_1", &id_m_loose_1); //isLooseMuon
            float id_m_medium_1 = 0; synchtree->Branch("id_m_medium_1", &id_m_medium_1); //isMediumMuon
            float id_m_tight_1 = 0; synchtree->Branch("id_m_tight_1", &id_m_tight_1); //isTightMuon
            float id_m_tightnovtx_1 = 0; synchtree->Branch("id_m_tightnovtx_1", &id_m_tightnovtx_1); //isTightnovtxMuon
            float id_m_highpt_1 = 0; synchtree->Branch("id_m_highpt_1", &id_m_highpt_1); //isHighPtMuon
            float id_e_mva_nt_loose_1 = 0; synchtree->Branch("id_e_mva_nt_loose_1", &id_e_mva_nt_loose_1);
            float id_e_cut_veto_1 = 0; synchtree->Branch("id_e_cut_veto_1", &id_e_cut_veto_1);
            float id_e_cut_loose_1 = 0; synchtree->Branch("id_e_cut_loose_1", &id_e_cut_loose_1);
            float id_e_cut_medium_1 = 0; synchtree->Branch("id_e_cut_medium_1", &id_e_cut_medium_1);
            float id_e_cut_tight_1 = 0; synchtree->Branch("id_e_cut_tight_1", &id_e_cut_tight_1);
            float trigweight_1 = 0; synchtree->Branch("trigweight_1", &trigweight_1);
            float againstElectronLooseMVA5_1 = 0; synchtree->Branch("againstElectronLooseMVA5_1", &againstElectronLooseMVA5_1);//same
            float againstElectronMediumMVA5_1 = 0; synchtree->Branch("againstElectronMediumMVA5_1", &againstElectronMediumMVA5_1); //same
            float againstElectronTightMVA5_1 = 0; synchtree->Branch("againstElectronTightMVA5_1", &againstElectronTightMVA5_1);//same
            float againstElectronVLooseMVA5_1 = 0; synchtree->Branch("againstElectronVLooseMVA5_1", &againstElectronVLooseMVA5_1);//same
            float againstElectronVTightMVA5_1 = 0; synchtree->Branch("againstElectronVTightMVA5_1", &againstElectronVTightMVA5_1);//same
            float againstMuonLoose3_1 = 0; synchtree->Branch("againstMuonLoose3_1", &againstMuonLoose3_1);//same
            float againstMuonTight3_1 = 0; synchtree->Branch("againstMuonTight3_1", &againstMuonTight3_1);//same
            float byCombinedIsolationDeltaBetaCorrRaw3Hits_1 = 0; synchtree->Branch("byCombinedIsolationDeltaBetaCorrRaw3Hits_1", &byCombinedIsolationDeltaBetaCorrRaw3Hits_1); //same
            float byIsolationMVA3newDMwoLTraw_1 = 0; synchtree->Branch("byIsolationMVA3newDMwoLTraw_1", &byIsolationMVA3newDMwoLTraw_1);//same
            float byIsolationMVA3oldDMwoLTraw_1 = 0; synchtree->Branch("byIsolationMVA3oldDMwoLTraw_1", &byIsolationMVA3oldDMwoLTraw_1);//same
            float byIsolationMVA3newDMwLTraw_1 = 0; synchtree->Branch("byIsolationMVA3newDMwLTraw_1", &byIsolationMVA3newDMwLTraw_1);//same
            float byIsolationMVA3oldDMwLTraw_1 = 0; synchtree->Branch("byIsolationMVA3oldDMwLTraw_1", &byIsolationMVA3oldDMwLTraw_1);//same
            float chargedIsoPtSum_1 = 0; synchtree->Branch("chargedIsoPtSum_1", &chargedIsoPtSum_1); //same
            float decayModeFinding_1 = 0; synchtree->Branch("decayModeFinding_1", &decayModeFinding_1);//same
            float decayModeFindingNewDMs_1 = 0; synchtree->Branch("decayModeFindingNewDMs_1", &decayModeFindingNewDMs_1); //same
            float neutralIsoPtSum_1 = 0; synchtree->Branch("neutralIsoPtSum_1", &neutralIsoPtSum_1);//same
            float puCorrPtSum_1 = 0; synchtree->Branch("puCorrPtSum_1", &puCorrPtSum_1);//same

            float pt_2 = 0; synchtree->Branch("pt_2", &pt_2);
            float phi_2 = 0; synchtree->Branch("phi_2", &phi_2);
            float eta_2 = 0; synchtree->Branch("eta_2", &eta_2);
            float m_2 = 0; synchtree->Branch("m_2", &m_2);
            float q_2 = 0; synchtree->Branch("q_2", &q_2);
            float d0_2 = 0; synchtree->Branch("d0_2", &d0_2);
            float dZ_2 = 0; synchtree->Branch("dZ_2", &dZ_2);
            float mt_2 = 0; synchtree->Branch("mt_2", &mt_2);
            float iso_2 = 0; synchtree->Branch("iso_2", &iso_2);
            float id_m_loose_2 = 0; synchtree->Branch("id_m_loose_2", &id_m_loose_2);
            float id_m_medium_2 = 0; synchtree->Branch("id_m_medium_2", &id_m_medium_2);
            float id_m_tight_2 = 0; synchtree->Branch("id_m_tight_2", &id_m_tight_2);
            float id_m_tightnovtx_2 = 0; synchtree->Branch("id_m_tightnovtx_2", &id_m_tightnovtx_2);
            float id_m_highpt_2 = 0; synchtree->Branch("id_m_highpt_2", &id_m_highpt_2);
            float id_e_mva_nt_loose_2 = 0; synchtree->Branch("id_e_mva_nt_loose_2", &id_e_mva_nt_loose_2);
            float id_e_cut_veto_2 = 0; synchtree->Branch("id_e_cut_veto_2", &id_e_cut_veto_2);
            float id_e_cut_loose_2 = 0; synchtree->Branch("id_e_cut_loose_2", &id_e_cut_loose_2);
            float id_e_cut_medium_2 = 0; synchtree->Branch("id_e_cut_medium_2", &id_e_cut_medium_2);
            float id_e_cut_tight_2 = 0; synchtree->Branch("id_e_cut_tight_2", &id_e_cut_tight_2);
            float trigweight_2 = 0; synchtree->Branch("trigweight_2", &trigweight_2);
            float againstElectronLooseMVA5_2 = 0; synchtree->Branch("againstElectronLooseMVA5_2", &againstElectronLooseMVA5_2);
            float againstElectronMediumMVA5_2 = 0; synchtree->Branch("againstElectronMediumMVA5_2", &againstElectronMediumMVA5_2);
            float againstElectronTightMVA5_2 = 0; synchtree->Branch("againstElectronTightMVA5_2", &againstElectronTightMVA5_2);
            float againstElectronVLooseMVA5_2 = 0; synchtree->Branch("againstElectronVLooseMVA5_2", &againstElectronVLooseMVA5_2);
            float againstElectronVTightMVA5_2 = 0; synchtree->Branch("againstElectronVTightMVA5_2", &againstElectronVTightMVA5_2);
            float againstMuonLoose3_2 = 0; synchtree->Branch("againstMuonLoose3_2", &againstMuonLoose3_2);
            float againstMuonTight3_2 = 0; synchtree->Branch("againstMuonTight3_2", &againstMuonTight3_2);
            float byCombinedIsolationDeltaBetaCorrRaw3Hits_2 = 0; synchtree->Branch("byCombinedIsolationDeltaBetaCorrRaw3Hits_2", &byCombinedIsolationDeltaBetaCorrRaw3Hits_2);
            float byIsolationMVA3newDMwoLTraw_2 = 0; synchtree->Branch("byIsolationMVA3newDMwoLTraw_2", &byIsolationMVA3newDMwoLTraw_2);
            float byIsolationMVA3oldDMwoLTraw_2 = 0; synchtree->Branch("byIsolationMVA3oldDMwoLTraw_2", &byIsolationMVA3oldDMwoLTraw_2);
            float byIsolationMVA3newDMwLTraw_2 = 0; synchtree->Branch("byIsolationMVA3newDMwLTraw_2", &byIsolationMVA3newDMwLTraw_2);
            float byIsolationMVA3oldDMwLTraw_2 = 0; synchtree->Branch("byIsolationMVA3oldDMwLTraw_2", &byIsolationMVA3oldDMwLTraw_2);
            float chargedIsoPtSum_2 = 0; synchtree->Branch("chargedIsoPtSum_2", &chargedIsoPtSum_2);
            float decayModeFinding_2 = 0; synchtree->Branch("decayModeFinding_2", &decayModeFinding_2);
            float decayModeFindingNewDMs_2 = 0; synchtree->Branch("decayModeFindingNewDMs_2", &decayModeFindingNewDMs_2);
            float neutralIsoPtSum_2 = 0; synchtree->Branch("neutralIsoPtSum_2", &neutralIsoPtSum_2);
            float puCorrPtSum_2 = 0; synchtree->Branch("puCorrPtSum_2", &puCorrPtSum_2);

            float pth = 0; synchtree->Branch("pth", &pth); //same
            float m_vis = 0; synchtree->Branch("m_vis", &m_vis);
            float m_sv = 0; synchtree->Branch("m_sv", &m_sv); //svfit
            float pt_sv = 0; synchtree->Branch("pt_sv", &pt_sv);
            float eta_sv = 0; synchtree->Branch("eta_sv", &eta_sv);
            float phi_sv = 0; synchtree->Branch("phi_sv", &phi_sv);
            float met_sv = 0; synchtree->Branch("met_sv", &met_sv);

            float met = 0; synchtree->Branch("met", &met);
            float metphi = 0; synchtree->Branch("metphi", &metphi);
            float mvamet = 0; synchtree->Branch("mvamet", &mvamet);
            float mvametphi = 0; synchtree->Branch("mvametphi", &mvametphi);
            float pzetavis = 0; synchtree->Branch("pzetavis", &pzetavis);
            float pzetamiss = 0; synchtree->Branch("pzetamiss", &pzetamiss);
            float mvacov00 = 0; synchtree->Branch("mvacov00", &mvacov00);//same
            float mvacov01 = 0; synchtree->Branch("mvacov01", &mvacov01);//same
            float mvacov10 = 0; synchtree->Branch("mvacov10", &mvacov10);//same
            float mvacov11 = 0; synchtree->Branch("mvacov11", &mvacov11);//same

            float mjj = 0; synchtree->Branch("mjj", &mjj); //same
            float jdeta = 0; synchtree->Branch("jdeta", &jdeta); //same
            float njetingap = 0; synchtree->Branch("njetingap", &njetingap);
            float jdphi = 0; synchtree->Branch("jdphi", &jdphi);
            float dijetpt = 0; synchtree->Branch("dijetpt", &dijetpt);
            float dijetphi = 0; synchtree->Branch("dijetphi", &dijetphi);
            float hdijetphi = 0; synchtree->Branch("hdijetphi", &hdijetphi);
            float visjeteta = 0; synchtree->Branch("visjeteta", &visjeteta);
            float ptvis = 0; synchtree->Branch("ptvis", &ptvis);

            float nbtag = 0; synchtree->Branch("nbtag", &nbtag);
            float njets = 0; synchtree->Branch("njets", &njets);
            float njetspt20 = 0; synchtree->Branch("njetspt20", &njetspt20);

            float jpt_1 = 0; synchtree->Branch("jpt_1", &jpt_1);
            float jeta_1 = 0; synchtree->Branch("jeta_1", &jeta_1);
            float jphi_1 = 0; synchtree->Branch("jphi_1", &jphi_1);
            float jrawf_1 = 0; synchtree->Branch("jrawf_1", &jrawf_1);
            float jmva_1 = 0; synchtree->Branch("jmva_1", &jmva_1);
            float jpfid_1 = 0; synchtree->Branch("jpfid_1", &jpfid_1);
            float jpuid_1 = 0; synchtree->Branch("jpuid_1", &jpuid_1);
            float jcsv_1 = 0; synchtree->Branch("jcsv_1", &jcsv_1);

            float jpt_2 = 0; synchtree->Branch("jpt_2", &jpt_2);
            float jeta_2 = 0; synchtree->Branch("jeta_2", &jeta_2);
            float jphi_2 = 0; synchtree->Branch("jphi_2", &jphi_2);
            float jrawf_2 = 0; synchtree->Branch("jrawf_2", &jrawf_2);
            float jmva_2 = 0; synchtree->Branch("jmva_2", &jmva_2);
            float jpfid_2 = 0; synchtree->Branch("jpfid_2", &jpfid_2);
            float jpuid_2 = 0; synchtree->Branch("jpuid_2", &jpuid_2);
            float jcsv_2 = 0; synchtree->Branch("jcsv_2", &jcsv_2);
     
            float bpt_1 = 0; synchtree->Branch("bpt_1", &bpt_1);
            float beta_1 = 0; synchtree->Branch("beta_1", &beta_1);
            float bphi_1 = 0; synchtree->Branch("bphi_1", &bphi_1);
            float brawf_1 = 0; synchtree->Branch("brawf_1", &brawf_1);
            float bmva_1 = 0; synchtree->Branch("bmva_1", &bmva_1);
            float bpfid_1 = 0; synchtree->Branch("bpfid_1", &bpfid_1);
            float bpuid_1 = 0; synchtree->Branch("bpuid_1", &bpuid_1);
            float bcsv_1 = 0; synchtree->Branch("bcsv_1", &bcsv_1);

            float bpt_2 = 0; synchtree->Branch("bpt_2", &bpt_2);
            float beta_2 = 0; synchtree->Branch("beta_2", &beta_2);
            float bphi_2 = 0; synchtree->Branch("bphi_2", &bphi_2);
            float brawf_2 = 0; synchtree->Branch("brawf_2", &brawf_2);
            float bmva_2 = 0; synchtree->Branch("bmva_2", &bmva_2);
            float bpfid_2 = 0; synchtree->Branch("bpfid_2", &bpfid_2);
            float bpuid_2 = 0; synchtree->Branch("bpuid_2", &bpuid_2);
            float bcsv_2 = 0; synchtree->Branch("bcsv_2", &bcsv_2);


            //111111111-----------don't touch from here------------------------------------------------------------------------------   
            /**/    unsigned short ci = 0;
            /**/    if(cut)
            /**/        cut->SetBranchAddress("cut",&ci);
            //111111111-----------don't touch to here------------------------------------------------------------------------------   
    

            // define variables
            unsigned short paircount = 0;  in->SetBranchAddress("paircount", &paircount);
            float run_ = 0; in->SetBranchAddress("run", &run_);
            float lumi_ = 0; in->SetBranchAddress("lumi", &lumi_);
            float evt_ = 0;  in->SetBranchAddress("evt", &evt_);
            bool isZtt_ = 0; in->SetBranchAddress("isZtt", &isZtt_);
            bool isZmt_ = 0; in->SetBranchAddress("isZmt", &isZmt_);
            bool isZet_ = 0; in->SetBranchAddress("isZet", &isZet_);
            bool isZee_ = 0; in->SetBranchAddress("isZee", &isZee_);
            bool isZmm_ = 0; in->SetBranchAddress("isZmm", &isZmm_);
            bool isZem_ = 0; in->SetBranchAddress("isZem", &isZem_);
            bool isZEE_ = 0; in->SetBranchAddress("isZEE", &isZEE_);
            bool isZMM_ = 0; in->SetBranchAddress("isZMM", &isZMM_);
            bool isZLL_ = 0; in->SetBranchAddress("isZLL", &isZLL_);
            int nup_ = 0; in->SetBranchAddress("nup", &nup_);

            float npv_ = 0; in->SetBranchAddress("npv", &npv_);
            float npu_ = 0; in->SetBranchAddress("npu", &npu_);

            std::vector<float> *taupt_ = 0;  in->SetBranchAddress("taupt", &taupt_);
            std::vector<float> *tauphi_ = 0;  in->SetBranchAddress("tauphi", &tauphi_);
            std::vector<float> *taueta_ = 0;  in->SetBranchAddress("taueta", &taueta_);
            std::vector<float> *taum_ = 0;  in->SetBranchAddress("taum", &taum_);
            std::vector<float> *tauq_ = 0;  in->SetBranchAddress("tauq", &tauq_);
            std::vector<float> *taumt_ = 0;  in->SetBranchAddress("taumt", &taumt_);

            std::vector<float> *againstElectronLooseMVA5_ = 0;  in->SetBranchAddress("againstElectronLooseMVA5", &againstElectronLooseMVA5_);
            std::vector<float> *againstElectronMediumMVA5_ = 0;  in->SetBranchAddress("againstElectronMediumMVA5", &againstElectronMediumMVA5_);
            std::vector<float> *againstElectronTightMVA5_ = 0;  in->SetBranchAddress("againstElectronTightMVA5", &againstElectronTightMVA5_);
            std::vector<float> *againstElectronVLooseMVA5_ = 0;  in->SetBranchAddress("againstElectronVLooseMVA5", &againstElectronVLooseMVA5_);
            std::vector<float> *againstElectronVTightMVA5_ = 0;  in->SetBranchAddress("againstElectronVTightMVA5", &againstElectronVTightMVA5_);
            std::vector<float> *againstMuonLoose3_ = 0;  in->SetBranchAddress("againstMuonLoose3", &againstMuonLoose3_);
            std::vector<float> *againstMuonTight3_ = 0;  in->SetBranchAddress("againstMuonTight3", &againstMuonTight3_);
            std::vector<float> *byCombinedIsolationDeltaBetaCorrRaw3Hits_ = 0;  in->SetBranchAddress("byCombinedIsolationDeltaBetaCorrRaw3Hits", &byCombinedIsolationDeltaBetaCorrRaw3Hits_);
            std::vector<float> *byIsolationMVA3newDMwoLTraw_ = 0;  in->SetBranchAddress("byIsolationMVA3newDMwoLTraw", &byIsolationMVA3newDMwoLTraw_);
            std::vector<float> *byIsolationMVA3oldDMwoLTraw_ = 0;  in->SetBranchAddress("byIsolationMVA3oldDMwoLTraw", &byIsolationMVA3oldDMwoLTraw_);
            std::vector<float> *byIsolationMVA3newDMwLTraw_ = 0;  in->SetBranchAddress("byIsolationMVA3newDMwLTraw", &byIsolationMVA3newDMwLTraw_);
            std::vector<float> *byIsolationMVA3oldDMwLTraw_ = 0;  in->SetBranchAddress("byIsolationMVA3oldDMwLTraw", &byIsolationMVA3oldDMwLTraw_);
            std::vector<float> *chargedIsoPtSum_ = 0;  in->SetBranchAddress("chargedIsoPtSum", &chargedIsoPtSum_);
            std::vector<float> *decayModeFinding_ = 0;  in->SetBranchAddress("decayModeFinding", &decayModeFinding_);
            std::vector<float> *decayModeFindingNewDMs_ = 0;  in->SetBranchAddress("decayModeFindingNewDMs", &decayModeFindingNewDMs_);
            std::vector<float> *neutralIsoPtSum_ = 0;  in->SetBranchAddress("neutralIsoPtSum", &neutralIsoPtSum_);
            std::vector<float> *puCorrPtSum_ = 0;  in->SetBranchAddress("puCorrPtSum", &puCorrPtSum_);

            std::vector<float> *mupt_ = 0;  in->SetBranchAddress("mupt", &mupt_);
            std::vector<float> *muphi_ = 0;  in->SetBranchAddress("muphi", &muphi_);
            std::vector<float> *mueta_ = 0;  in->SetBranchAddress("mueta", &mueta_);
            std::vector<float> *mum_ = 0;  in->SetBranchAddress("mum", &mum_);
            std::vector<float> *muq_ = 0;  in->SetBranchAddress("muq", &muq_);
            std::vector<float> *mud0_ = 0;  in->SetBranchAddress("mud0", &mud0_);
            std::vector<float> *mudz_ = 0;  in->SetBranchAddress("mudz", &mudz_);
            std::vector<float> *mumt_ = 0;  in->SetBranchAddress("mumt", &mumt_);
            std::vector<float> *muiso_ = 0;  in->SetBranchAddress("muiso", &muiso_);
            std::vector<float> *muisLooseMuon_ = 0;  in->SetBranchAddress("muisLooseMuon", &muisLooseMuon_);
            std::vector<float> *muisTightMuon_ = 0;  in->SetBranchAddress("muisTightMuon", &muisTightMuon_);
            std::vector<float> *muisHighPtMuon_ = 0;  in->SetBranchAddress("muisHighPtMuon", &muisHighPtMuon_);
            std::vector<float> *muisMediumMuon_ = 0;  in->SetBranchAddress("muisMediumMuon", &muisMediumMuon_);
            std::vector<float> *muisTightnovtxMuon_ = 0;  in->SetBranchAddress("muisTightnovtxMuon", &muisTightnovtxMuon_);

            std::vector<float> *pth_ = 0;  in->SetBranchAddress("pth", &pth_);
            std::vector<float> *m_sv_ = 0;  in->SetBranchAddress("m_sv", &m_sv_);

            std::vector<float> *mvacov00_ = 0;  in->SetBranchAddress("mvacov00", &mvacov00_);
            std::vector<float> *mvacov01_ = 0;  in->SetBranchAddress("mvacov01", &mvacov01_);
            std::vector<float> *mvacov10_ = 0;  in->SetBranchAddress("mvacov10", &mvacov10_);
            std::vector<float> *mvacov11_ = 0;  in->SetBranchAddress("mvacov11", &mvacov11_);


        for (int i = 0; i < in->GetEntries(); i++) {
            //2222222222222-----------don't touch from here------------------------------------------------------------------------------   
            /**/   in->GetEntry(i); 
            /**/   if(cut){
            /**/      cut->GetEntry(i);
            /**/       if(!ci) continue;   
            /**/   }
            //2222222222222-----------don't touch to here------------------------------------------------------------------------------   

            run = run_;
            lumi = lumi_;
            evt = evt_;
            isZtt=isZtt_;
            isZmt=isZmt_;
            isZet=isZet_;
            isZee=isZee_;
            isZmm=isZmm_;
            isZem=isZem_;
            isZEE=isZEE_;
            isZMM= isZMM_;
            isZLL=isZLL_;

            NUP= nup_; 
            npv = npv_;
            npu = npu_;
            
            if(cut){
                unsigned short one = 1;
                for(int i = 0; i < paircount; i++){
                    if (ci & one){
                        pt_1 = (*taupt_)[i];
                        phi_1 = (*tauphi_)[i];
                        eta_1 = (*taueta_)[i];
                        m_1 = (*taum_)[i];
                        q_1 = (*tauq_)[i];
                        mt_1 = (*taumt_)[i];
                        againstElectronLooseMVA5_1 = (*tauagainstElectronLooseMVA5_)[i];
                        againstElectronMediumMVA5_1 = (*tauagainstElectronMediumMVA5_)[i];
                        againstElectronTightMVA5_1 = (*tauagainstElectronTightMVA5_)[i];
                        againstElectronVLooseMVA5_1 = (*tauagainstElectronVLooseMVA5_)[i];
                        againstElectronVTightMVA5_1 = (*tauagainstElectronVTightMVA5_)[i];
                        againstMuonLoose3_1 = (*tauagainstMuonLoose3_)[i];
                        againstMuonTight3_1 = (*tauagainstMuonTight3_)[i];
                        byCombinedIsolationDeltaBetaCorrRaw3Hits_1 = (*taubyCombinedIsolationDeltaBetaCorrRaw3Hits_)[i];
                        byIsolationMVA3newDMwoLTraw_1 = (*taubyIsolationMVA3newDMwoLTraw_)[i];
                        byIsolationMVA3oldDMwoLTraw_1 = (*taubyIsolationMVA3oldDMwoLTraw_)[i];
                        byIsolationMVA3newDMwLTraw_1 = (*taubyIsolationMVA3newDMwLTraw_)[i];
                        byIsolationMVA3oldDMwLTraw_1 = (*taubyIsolationMVA3oldDMwLTraw_)[i];
                        chargedIsoPtSum_1 = (*tauchargedIsoPtSum_)[i];
                        decayModeFinding_1 = (*taudecayModeFinding_)[i];
                        decayModeFindingNewDMs_1 = (*taudecayModeFindingNewDMs_)[i];
                        neutralIsoPtSum_1 = (*tauneutralIsoPtSum_)[i];
                        puCorrPtSum_1 = (*taupuCorrPtSum_)[i];

                        pt_2 = (*mupt_)[i];
                        phi_2 = (*muphi_)[i];
                        eta_2 = (*mueta_)[i];
                        m_2 = (*mum_)[i];
                        q_2 = (*muq_)[i];
                        d0_2 = (*mud0_)[i];
                        dZ_2 = (*mudz_)[i];
                        mt_2 = (*mumt_)[i];
                        iso_2 = (*muiso_)[i];
                        id_m_loose_2 = (*isLooseMuon)[i];
                        id_m_medium_2 = (*isMediumMuon_)[i];
                        id_m_tight_2 = (*isTightMuon_)[i];
                        id_m_tightnovtx_2 = (*isTightnovtxMuon_)[i];
                        id_m_highpt_2 = (*isHighPtMuon_)[i];

                        pth = (*pth_)[i];
                        m_sv = (*m_sv_)[i];

                        mvacov00 = (*mvacov00_)[i];
                        mvacov01 = (*mvacov01_)[i];
                        mvacov10 = (*mvacov10_)[i];
                        mvacov11 = (*mvacov11_)[i];

                        break;
                    }
                    one = one << 1;
                }
            }
            else{
                        pt_1 = (*taupt_)[0];
                        phi_1 = (*tauphi_)[0];
                        eta_1 = (*taueta_)[0];
                        m_1 = (*taum_)[0];
                        q_1 = (*tauq_)[0];
                        mt_1 = (*taumt_)[0];

                        pt_2 = (*mupt_)[0];
                        phi_2 = (*muphi_)[0];
                        eta_2 = (*mueta_)[0];
                        m_2 = (*mum_)[0];
                        q_2 = (*muq_)[0];
                        d0_2 = (*mud0_)[0];
                        dZ_2 = (*mudz_)[0];
                        mt_2 = (*mumt_)[0];
            }
            
            synchtree->Fill();
        }
        synchtree->Write();
        delete synchtree;
        } else {std::cout << "synchronizer ERROR: tree exist;";}
        delete f;

    }
    public:
    synchronizer(std::string name_){

        name = name_;
    }
    

};

#endif


