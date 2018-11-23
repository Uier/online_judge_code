#include <iostream>
#include <algorithm>
#define maxn 200005
#define int long long
using namespace std;
const int mod = 998244353;
int n, m, dp[maxn], cnt, ans;
string s, t;
main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	dp[0] = 1;
	for ( int i=1; i<maxn; ++i )	dp[i] = (dp[i-1]<<1)%mod;
	cin >> n >> m >> s >> t;
	reverse(s.begin(),s.end());
	reverse(t.begin(),t.end());
	for ( int i=0; i<m; ++i )	if ( t[i] == '1' )	cnt++;
	for ( int i=0; i<min(n,m); ++i ) {
		if ( s[i] == '1' )	ans = (ans+(dp[i]*cnt)%mod)%mod;
		if ( t[i] == '1' )	cnt--;
	}
	cout << ans << '\n';
	return 0;
}

