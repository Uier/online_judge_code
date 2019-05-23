#include <iostream>
#include <math.h>
#define maxn 100005
using namespace std;
int dp[maxn];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, a, b, c;
	cin >> n >> a >> b;
	dp[2] = abs(b-a);
	for ( int i=3, x; i<=n; ++i ) {
		cin >> c;
		dp[i] = min(dp[i-2]+abs(c-a),dp[i-1]+abs(c-b));
		a = b;
		b = c;
	}
	cout << dp[n] << '\n';
	return 0;
}
