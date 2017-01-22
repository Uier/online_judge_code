#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int main()
{
	string fname;
	int repcnt;
	cin>>fname>>repcnt;
	fstream input;
	input.open(fname.c_str(),fstream::in);
	string s;
	getline(input,s);
	int ans=0;
	while(s.size())
	{
		/** 字串取代 隨便你寫 **/
		string search;
		cin>>search;
		size_t pos = 0;
	    while ((pos = s.find(search, pos)) != std::string::npos) {
			ans++;
			/*s.replace(pos, search.length(), replace);
			pos += replace.length();*/
	    }
	    /****/ 
	}
	cout << ans << endl;
		
		
}
