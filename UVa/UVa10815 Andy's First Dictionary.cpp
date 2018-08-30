#include<iostream>
#include<set>
#include<sstream>
using namespace std;
set<string> st;
int main() {
	string s, tmp;
	while ( getline(cin, s) ) {
		for ( int i=0; i<s.size(); i++ )
			if ( s[i] >= 'A' && s[i] <= 'Z' )	s[i] += 32;
			else if ( s[i] < 'a' || s[i] > 'z' )	s[i] = ' ';
		istringstream iss(s);
		while ( iss >> tmp )	st.insert(tmp);
	}
	for ( string i : st )	cout << i << endl;
	return 0;
}

