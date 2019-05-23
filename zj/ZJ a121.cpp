#include <iostream>
#include <unordered_map>
#define int long long
using namespace std;
unordered_map<int,int> dp;
inline bool prm(int x) {
	if ( dp[x] )	return (dp[x]==1 ? 1 : 0);
	bool f = 1;
	for ( int i=2; i*i<=x; ++i )
		if ( x%i == 0 ) {
			dp[x] = 2;
			return 0;
		}
	return dp[x]=1;
}
int32_t main() {
	ios::sync_with_stdio(false);
	//   sync_with_YinHsuan(true);
	cin.tie(0);
	int a, b;
	dp[1] = 2;
	while ( cin >> a >> b ) {
		int ans = 0;
		for ( int i=a; i<=b; ++i ) 
			if ( prm(i) )	ans++;
		cout << ans << '\n';
	}
	return 0;
}
