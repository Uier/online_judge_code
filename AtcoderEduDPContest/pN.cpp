#include <iostream>
#include <string.h>
#define maxn 401
#define int long long
using namespace std;
typedef pair<int,int> pii;
int arr[maxn];
pii dp[maxn][maxn];
main() {
	ios::sync_with_stdio(false);
	//   sync_with_YinHsuan(true);
	cin.tie(0);
	int n;
	cin >> n;
	memset(dp,0x7f,sizeof(dp));
	for ( int i=1; i<=n; ++i )	cin >> arr[i];
	for ( int i=1; i<=n; ++i )	dp[i][i] = make_pair(arr[i],0);
	for ( int i=2; i<=n; ++i )
		for ( int j=1; j+i-1<=n; ++j ) {
			int l = j, r = j+i-1;
			pii cost = make_pair(0,-1);
			for ( int k=l; k<r; ++k )
				if ( cost.second == -1 || dp[l][k].second+dp[k+1][r].second+dp[l][k].first+dp[k+1][r].first < cost.second )
					cost = make_pair(dp[l][k].first+dp[k+1][r].first,dp[l][k].second+dp[k+1][r].second+dp[l][k].first+dp[k+1][r].first);
			dp[l][r] = cost;
		}
	cout << dp[1][n].second << '\n';
	return 0;
}

