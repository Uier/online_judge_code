// By KRT girl xiplus
// http://www.hpcodewars.com.tw/past/cw3/problems/2015CodeWarsProblemsFinal_Ch.pdf 
#include <iostream>
//#include <fstream>
#include <cstring>
using namespace std;
int main(){/* 
	string fname;
	int repcnt;
	cin>>fname>>repcnt;
	fstream input;
	input.open(fname.c_str(),fstream::in);*/ 
	string s;
	getline(cin,s);
//	input.close();
	int ans=0;
	int repcnt;
	while(repcnt--){
		/** 字串取代 隨便你寫 **/
		string search;
		cin>>search;
		string replace="***";
		size_t pos = 0;
	    while ((pos = s.find(search, pos)) != std::string::npos) {
			ans++;
			s.replace(pos, search.length(), replace);
			pos += replace.length();
	    }
	}
	cout << ans << endl;
	/*
	// 取得主檔名 
	string fnewname="";
	for(int i=0;i<fname.size();i++){
		if(fname[i]!='.'){
			fnewname+=fname[i];
		}else {
			break;
		}
	}
	fnewname+="_mod.txt";
	fstream output;
	output.open(fnewname.c_str(),fstream::out);
	output<<s;*/
//	out.close();
}
