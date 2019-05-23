#include <iostream>
#include <vector>
#include <string.h>
#define maxn 300005
using namespace std;
vector<int> G[maxn];
int V[maxn];
int odd, even, invalid;
long long dp[maxn];
const long long mod = 998244353;
void dfs(int x, int cur) {
	V[x] = cur;
	if ( cur > 0 )	odd++;
	else	even++;
	for ( int i : G[x] )
		if ( V[i] == 0 )	dfs(i,cur*-1);
		else if ( V[i]*cur > 0 )	invalid = true;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t, n, m;
	cin >> t;
	dp[0] = 1;
	for ( int i=1; i<maxn; ++i )	dp[i] = (dp[i-1]<<1)%mod;
	while ( t-- && cin >> n >> m ) {
		memset(V,0,sizeof(int)*(n+1));
		for ( int i=0, a, b; i<m; ++i ) {
			cin >> a >> b;
			G[a].emplace_back(b);
			G[b].emplace_back(a);
		}
		bool flag = false;
		long long ans = 1;
		for ( int i=1; i<=n; ++i )
			if ( V[i] == 0 ) {
				odd = even = invalid = 0;
				dfs(i,1);
				ans *= (dp[odd]+dp[even])%mod;
				ans %= mod;
				flag |= invalid;
			}
		if ( flag )	cout << 0 << '\n';
		else	cout << ans << '\n';
		for ( int i=1; i<=n; ++i )	G[i].clear();
	}
	return 0;
}

