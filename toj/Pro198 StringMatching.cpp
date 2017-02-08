#include <iostream>
using namespace std;
string s, t, a, b;
int fail[100005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	while ( getline(cin,a) && getline(cin,b) ) {
		bool match = false;
		s.clear();	t.clear();
		for ( char c : a )
			if ( c >= 'a' && c <= 'z' )	s.push_back(c);
			else if ( c >= 'A' && c <= 'Z' ) s.push_back(c+32);
		for ( char c : b )
			if ( c >= 'a' && c <= 'z' )	t.push_back(c);
			else if ( c >= 'A' && c <= 'Z' ) t.push_back(c+32);
		if ( t == "" )	cout << "Yes\n";
		else if ( s == "" )	cout << "No\n";
		else {
			int j = fail[0] = -1;
			for ( int i=1; i<t.size(); i++ ) {
				while ( j != -1 && t[i] != t[j+1] )	j = fail[j];
				if ( t[i] == t[j+1] )	j++;
				fail[i] = j;
			}
			j = -1;
			for ( int i=0; i<s.size(); i++ ) {
				while ( j != -1 && s[i] != t[j+1] )	j = fail[j];
				if ( s[i] == t[j+1] )	j++;
				if ( j+1 == t.size() ) {
					match = true;
					break;
				}
			}
			if ( match )	cout << "Yes\n";
			else	cout << "No\n";
		}
	}
	return 0;
}

