#include <iostream>
#include <string.h>
using namespace std;
int a[205];
bool dp[50010];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, n, x=0, sum=0;
	cin >> t;
	while ( t-- ) {
		cin >> n;
		memset(dp,false,sizeof dp);
		x = sum = 0;
		for ( int i=0; i<n; i++ ) {
			cin >> a[i];
			sum += a[i];
		}
		dp[0] = true;
		for ( int i=0; i<n; i++ )
			for ( int j=sum/2; j>=0; j-- )
				if ( dp[j] )
					dp[j+a[i]] = true;
		while ( !dp[sum/2+x] && !dp[sum/2-x] )	x++;
		if ( n == 1 )	cout << sum << '\n';
		else	cout << ((sum%2)?(x*2+1):(x*2)) << '\n';
	}
	return 0;
}

