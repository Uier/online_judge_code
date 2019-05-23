#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	string s;
	cin >> n >> k >> s;
	int ans = 0;
	for ( char c='a'; c<='z'; ++c ) {
		int cnt = 0;
		for ( int i=0; i<n; ++i ) {
			if ( s[i] == c ) {
				int tmp = 1;
				for ( int j=i+1; j<n&&j<i+k; ++j ) {
					if ( s[j] == c )	tmp++;
					else	break;
				}
				if ( tmp == k )	cnt++;
				i = i+tmp-1;
			}
		}
		ans = max(ans,cnt);
	}
	cout << ans << '\n';
	return 0;
}

