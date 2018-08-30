#include <iostream>
using namespace std;
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int n, p, cnt = 0;
	string s;
	cin >> n >> p;
	cin >> s;
	for ( int i=p; i<n; ++i ) {
		if ( s[i] == '.' && s[i-p] == '.' )
			continue;
		if ( s[i] == '.' && s[i-p] != '.' ) {
			if ( s[i-p] == '1' )	s[i] = '0';
			else	s[i] = '1';
		} else if ( s[i] != '.' && s[i-p] == '.' ) {
			if ( s[i] == '1' )	s[i-p] = '0';
			else	s[i-p] ='1';
		}
		if ( s[i] == s[i-p] )	cnt++;
	}
	if ( cnt == n-p )	cout << "No\n";
	else {
		for ( int i=0; i<n; ++i )
			if ( s[i] == '.' )
				s[i] = '1';
		cout << s <<'\n';
	}
	return 0;
}

