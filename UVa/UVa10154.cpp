#include <iostream>
#include <algorithm>
using namespace std;
// dp[i][j] = front i turtles, min weight of taking j turtles
int dp[5610][5610];
const int inf = 0x7ffffff;
struct turtle {
	int w, c;
} a[5610];
bool operator < (turtle x, turtle y) {
	return x.c < y.c;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0;
	while ( cin >> a[n+1].w >> a[n+1].c ) {
		a[n+1].c -= a[n+1].w;
		n++;
	}
	sort(a,a+n+1);
	for ( int i=0; i<=n; i++ ) {
		dp[i][0] = 0;
		for ( int j=1; j<=n; j++ )
			dp[i][j] = inf;
	}
	for ( int i=1; i<=n; i++ )
		for ( int j=1; j<=i; j++ )
			if ( a[i].c >= dp[i-1][j-1] )
				dp[i][j] = min(dp[i-1][j],dp[i-1][j-1]+a[i].w);
	for ( int i=n; i>=0; i-- )
		if ( dp[n][i] != inf ) {
			cout << i << '\n';
			break;
		}
	return 0;
}

