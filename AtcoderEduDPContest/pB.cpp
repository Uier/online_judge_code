#include <iostream>
#include <math.h>
#define maxn 100005
using namespace std;
int arr[maxn], dp[maxn];
int main() {
	ios::sync_with_stdio(false);
	//   sync_with_YinHsuan(true);
	cin.tie(0);
	int n, k, a, b, c;
	cin >> n >> k >> arr[1];
	for ( int i=2; i<=n; ++i ) {
		cin >> arr[i];
		int mn = -1;
		for ( int j=i-1; j>=i-k&&j>=1; --j )
			if ( mn == -1 || dp[j]+abs(arr[i]-arr[j]) < mn )
				mn = dp[j] + abs(arr[i]-arr[j]);
		dp[i] = mn;
	}
	cout << dp[n] << '\n';
	return 0;
}
