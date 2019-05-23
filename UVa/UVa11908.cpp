#include <iostream>
#include <algorithm>
#include <string.h>
#define maxn 30005
using namespace std;
struct post {
	int l, r, cost;
} arr[maxn];
int dp[200001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t, n, cs = 1;
	cin >> t;
	while ( t-- && cin >> n ) {
		for ( int i=0; i<n; ++i ) {
			cin >> arr[i].l >> arr[i].r >> arr[i].cost;
			arr[i].r += (arr[i].l-1);
		}
		sort(arr,arr+n,[](post x, post y){return x.r < y.r;});
		int pre = 0;
		for ( int i=0; i<n; ++i ) {
			int l = arr[i].l, r = arr[i].r;
			for ( int j=pre+1; j<=r; ++j )	dp[j] = max(dp[j],dp[j-1]);
			dp[r] = max(dp[r],dp[l-1]+arr[i].cost);
			pre = r;
		}
		cout << "Case " << cs++ << ": " << dp[pre] << '\n';
		memset(dp,0,sizeof(int)*(pre+1));
	}
	return 0;
}

