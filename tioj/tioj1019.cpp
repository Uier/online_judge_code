#include <iostream>
#include <math.h>
#include <string.h>
#define maxn 1005
#define int long long
using namespace std;
int arr[maxn], dp[maxn];
main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t, n;
	cin >> t;
	while ( t-- && cin >> n ) {
		for ( int i=0; i<n; ++i )	cin >> arr[i];
		memset(dp,0,sizeof(dp));
		dp[1] = abs(arr[1]-arr[0]);
		for ( int i=2; i<n; ++i )	dp[i] = min(dp[i-1]+abs(arr[i-1]-arr[i]), dp[i-2]+abs(arr[i-2]-arr[i]));
		cout << dp[n-1] << '\n';
	}
	return 0;
}

