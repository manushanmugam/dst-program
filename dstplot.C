/*
Program to read the rood file created using dstread.cpp
*/
{
gROOT->Reset();
TFile *f=new TFile("dst2005.root");
TTree *t=(TTree*)f->Get("dst");
TCanvas *c1=new TCanvas();
t->Draw("dst:td");
}
