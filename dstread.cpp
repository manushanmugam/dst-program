/* This program reads the dst IAGA format and stores it in root file for plotting the data
To compile this program "g++ filename -o name `root-config --glibs --cflags"
*/

#include<iostream>
#include<fstream>
#include<cstdlib>
#include "TFile.h"
#include "TNtuple.h"
using namespace std;

int main(){
	string date, time, hour;
	string DATE,TIME,DOY,DST;
	float doy, dst;
  	float hh,td;
  	ifstream readfile("dst_2011_iaga.dat"); 
  	readfile>>DATE>>TIME>>DOY>>DST;
  	TFile *f =  new TFile("dst2011.root","RECREATE");
  	TNtuple *ntuple = new TNtuple("dst","year2011","td:hh:doy:dst");
  	while(true){
    	readfile>>date>>time>>doy>>dst;
    	if(readfile.eof()) break;
    	hour=time.substr(0,2);
    	hh=atoi(hour.c_str());
    	td=doy+hh/24.0;
    	ntuple->Fill(td,hh,doy,dst);
		cout<<date<<"\t"<<time<<"\t"<<hh<<"\t"<<td<<endl;   		
  	}
  	f->Write();
  	f->Close();
  	readfile.close();
  	return 0;
}
