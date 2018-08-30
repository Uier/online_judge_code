#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	string s, t;
	cin >> n >> m;
	cin >> s >> t;
	int tmp = n, pos = 1;
	for ( int i=1; i<=m-n+1; ++i ) {
		int tt = n;
		for ( int j=1, k=i; j<=n; ++j, ++k ) {
			if ( t[k-1] == s[j-1] )
				tt--;
		}
		if ( tt < tmp ) {
			tmp = tt;
			pos = i;
		}
	}
	cout << tmp << '\n';
	for ( int i=pos, j=1; i<pos+n; ++i, ++j )
		if ( t[i-1] != s[j-1] )
			cout << j << ' ';
	cout << '\n';
	return 0;
}

