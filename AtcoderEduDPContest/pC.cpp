#include <iostream>
#define maxn 100005
using namespace std;
int dp[maxn][3];
int main() {
	ios::sync_with_stdio(false);
	//   sync_with_YinHsuan(true);
	cin.tie(0);
	int n;
	cin >> n;
	for ( int i=1, a, b, c; i<=n; ++i ) {
		cin >> a >> b >> c;
		dp[i][0] = max(dp[i-1][1],dp[i-1][2])+a;
		dp[i][1] = max(dp[i-1][0],dp[i-1][2])+b;
		dp[i][2] = max(dp[i-1][0],dp[i-1][1])+c;
	}
	cout << max(dp[n][0],max(dp[n][1],dp[n][2])) << '\n';
	return 0;
}

