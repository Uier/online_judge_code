#include <iostream>
#include <algorithm>
#include <map>
#define maxp 32
#define int long long
using namespace std;
int dp[maxp] = {1};
map<int,int> DP;
int find(int x) {
	if ( x <= 2 )	return x < 0 ? 0 : x;
	if ( DP[x] )	return DP[x];
	int pos = upper_bound(dp,dp+maxp,x)-dp-1;
	return DP[x] = x-dp[pos]+1+find(dp[pos]-1)+find(x-dp[pos]);
}
main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for ( int i=1; i<maxp; ++i )	dp[i] = dp[i-1]<<1;
	int a, b, cs = 1;
	while ( cin >> a >> b && (a||b) )
		cout << "Case " << cs++ << ": " << find(b)-find(a-1) << '\n';
	return 0;
}
