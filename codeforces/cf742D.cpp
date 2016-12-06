#include <iostream>
using namespace std;
int n, m, W, x, y, w[101005], b[101005], pr[101005], dp[1005];
bool tm[1005];
int solve() {
	for ( int i=0; i<n; i++ )
		for ( int j=w[i]; j<=W; j++ )
			dp[j] = max(dp[j],dp[j-w[i]]+b[i]);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> W;
	int k = n;
	for ( int i=0; i<n; i++ )
		cin >> w[i];
	for ( int i=0; i<n; i++ )
		cin >> b[i];
	for ( int i=0; i<m; i++ ) {
		cin >> x >> y;
		if ( pr[x] == pr[y] && pr[x] == 0 )	pr[x] = pr[y] = k++;
		else if ( pr[y] )	pr[x] = pr[y];
		else	pr[y] = pr[x];
		if ( !tm[x] ) {
			tm[x] = true;
			w[pr[x]] += w[x];
			b[pr[x]] += b[x];	
		}
		if ( !tm[y] ) {
			tm[y] = true;
			w[pr[y]] += w[y];
			b[pr[y]] += b[y];	
		}
	}
	cout << solve() << '\n';
	return 0;
}

