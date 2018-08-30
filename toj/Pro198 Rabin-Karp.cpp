#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s, t;
	while ( getline(cin,s) && getline(cin,t) ) {
		int ls = s.size(), lt = t.size();
		string a = "", b = "";
		for ( int i=0; i<ls; ++i )
			if ( s[i] >= 'A' && s[i] <= 'Z' )	a += char(s[i]+32);
			else if ( s[i] >= 'a' && s[i] <= 'z' )	a += s[i];
		for ( int i=0; i<lt; ++i )
			if ( t[i] >= 'A' && t[i] <= 'Z' )	b += char(t[i]+32);
			else if ( t[i] >= 'a' && t[i] <= 'z' )	b += t[i];
		int la = a.size(), lb = b.size(), base = 31, p = 2147483647;
		long long key = 0, hash = 0, rolling = 1;
		for ( int i=0; i<lb-1; ++i )
			rolling = (rolling*base)%p;
		for ( int i=0; i<lb; ++i ) {
			key = ((key*base)%p+ b[i]-'a')%p;
			hash = ((hash*base)%p + a[i]-'a')%p; 
		}
		bool ans = false;
		for ( int i=0; i<la-lb+1; ++i ) {
			if ( key == hash ) {
				bool flag = true;
				for ( int j=i, k=0; j<i+lb; ++j, ++k ) 
					if ( a[j] != b[k] )
						flag = false;
				ans |= flag;
			}
			if ( i < la-lb )
				hash = ((hash - (a[i]-'a')*rolling)*base + a[i+lb]-'a')%p;
		}
		cout << (ans ? "Yes\n" : "No\n");
	}
	return 0;
}

