#include <iostream>
#include <algorithm>
using namespace std;
int dp[21], arr[35];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	dp[0] = 1;
	for ( int i=1; i<21; ++i )	dp[i] = dp[i-1]<<1;
	/*
	WWWWWWWWWWW
	AAAAAAAAAAA
	*/
	int n;
	while ( cin >> n && n ) {
		for ( int i=0; i<n; ++i )	cin >> arr[i];
		int ans = 0;
		for ( int k=0; k<n; ++k ) {
			int mx = arr[k];
			int dig = upper_bound(dp,dp+21,mx)-dp-1;
			for ( int i=dig; i>0; --i )
				for ( int j=0; j<n; ++j )
					if ( arr[j] < (1<<i) && ((arr[j]&(1<<i-1))^(mx&(1<<i-1))) )
						mx ^= arr[j];
			ans = max(ans,mx);
		}
		cout << ans << '\n';
	}
	return 0;
}

