#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	while ( cin >> s && s != "0" ) {
		int len = s.size(), a = 0, b = 0;
		for ( int i=0; i<len; ++i ) {
			if ( i&1 )	a += s[i]-'0';
			else	b += s[i]-'0';
		}
		int c = a-b;
		if ( c < 0 )	c *= -1;
		cout << s;
		if ( c%11 == 0 )	cout << " is a multiple of 11.\n";
		else	cout << " is not a multiple of 11.\n"; 
	}
	return 0;
}

