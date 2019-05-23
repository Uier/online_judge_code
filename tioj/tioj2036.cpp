#include <iostream>
#include <map>
using namespace std;
long long n, cnt[4][8];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for ( int i=0, c, a, r, d; i<n; ++i ) {
		cin >> c >> a >> r >> d;
		cnt[c][(a<<2)+(r<<1)+d]++; // hash
	}
	long long ans = 0;
	for ( int i=0; i<8; ++i )
		for ( int j=0; j<8; ++j )
			for ( int k=0; k<8; ++k )
				if ( ((i|j)|k) == 7 )
					ans += cnt[1][i]*cnt[2][j]*cnt[3][k];
	cout << ans << '\n';
	return 0;
}

