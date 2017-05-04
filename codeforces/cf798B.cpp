#include <iostream>
using namespace std;
string s[52];
void append(int x) {
	char c = s[x][0];
	for ( int i=0; i<s[x].size()-1; ++i )
		s[x][i] = s[x][i+1];
	s[x][s[x].size()-1] = c;
}
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int n, ans = 1e9;
	cin >> n;
	for ( int i=0; i<n; ++i )
		cin >> s[i];
	for ( int i=0; i<n; ++i ) {
		int tmp = 0;
		for ( int j=0; j<n; ++j ) {
			int flt = 0;
			s[n] = s[j];
			while ( s[i] != s[n] ) {
				append(n);
				tmp++;
				flt++;
				if ( flt > 55 ) {
					ans = -1;
					break;
				}
			}
		}
		ans = min(ans,tmp);
	}
	cout << ans << '\n';
	return 0;
}

