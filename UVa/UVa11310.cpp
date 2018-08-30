#include <iostream>
using namespace std;
long long dp[41];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	dp[1] = 1;	dp[2] = 5;	dp[3] = 11;
	for ( int i=4; i<41; ++i )
		dp[i] = dp[i-1]+dp[i-2]*4+dp[i-3]*2;
	int t, n;
	cin >> t;
	while ( t-- && cin >> n )	cout << dp[n] << '\n';
	return 0;
}

