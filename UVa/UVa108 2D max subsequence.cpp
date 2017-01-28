#include <iostream>
using namespace std;
int a[105][105], b[105], dp[105];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for ( int i=0; i<n; i++ )
		for ( int j=0; j<n; j++ ) {
			cin >> a[i][j];
			if ( i )
				a[i][j] += a[i-1][j];
		}
	int fians=-1000000000;
	for ( int i=0; i<n; i++ )
		for ( int j=i; j<n; j++ ) {
			int ans=-1000000000;
			for ( int k=0; k<n; k++ ) {
				if ( i == j )
					b[k] = a[i][k];
				else
					b[k] = a[j][k] - a[i][k];
				if ( k == 0 )
					dp[k] = b[k];
				else if ( dp[k-1] > 0 )
					dp[k] = dp[k-1] + b[k];
				else
					dp[k] = b[k];
				if ( dp[k] > ans )
					ans = dp[k];
			}
			if ( ans > fians )
				fians = ans;
		}
	cout << fians << '\n';
	return 0;
}

