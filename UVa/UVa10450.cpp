#include <iostream>
#define int long long
using namespace std;
int t, n, dp[51], cs = 1;
main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	dp[0] = dp[1] = 1;
	for ( int i=2; i<51; ++i )	dp[i] = dp[i-1] + dp[i-2];
	cin >> t;
	while ( t-- && cin >> n )
		cout << "Scenario #" << cs++ << ":\n" << dp[n]+dp[n-1] << "\n\n";
	return 0;
}

