#include <iostream>
#define maxn 3000
using namespace std;
double dp[maxn][maxn];
int main() {
	ios::sync_with_stdio(false);
	//   sync_with_YinHsuan(true);
	cin.tie(0);
	int n;
	double p, ans = 0;
	cin >> n >> p;
	dp[1][0] = p;
	dp[0][1] = 1-p;
	for ( int i=2; i<=n; ++i ) {
		cin >> p;
		for ( int j=0; j<i; ++j ) {
			dp[i-j][j] += dp[i-1-j][j] * p;
			dp[j][i-j] += dp[j][i-1-j] * (1-p);
		}
	}
	for ( int i=n; i>(n-i); --i )	ans += dp[i][n-i];
	printf("%.10lf\n", ans);
	return 0;
}

