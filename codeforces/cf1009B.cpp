#include <iostream>
#define maxn 100005
using namespace std;
int a[maxn][3];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	int len = s.size(), pos = 0;
	bool zer = 0, two = 0;
	for ( int i=0; i<len; ++i ) {
		if ( s[i] == '0' ) {
			if ( two ) {
				two = 0;
				pos++;
			}
			zer = 1;
		} else if ( s[i] == '2' ) {
			if ( zer ) {
				zer = 0;
				pos++;
			}
			two = 1;
		}
		a[pos][s[i]-'0']++;
	}
	for ( int i=0, x; i<=pos; ++i ) {
		x = a[i][0];
		for ( int j=0; j<x; ++j )	cout << 0;
		x = a[i][1];
		for ( int j=0; j<x; ++j )	cout << 1;
		x = a[i][2];
		for ( int j=0; j<x; ++j )	cout << 2;
	}
	cout << '\n';
	return 0;
}

