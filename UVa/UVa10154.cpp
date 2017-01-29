//	undone
#include <iostream>
#include <algorithm>
using namespace std;
int dp[5610];
const int inf = 0x7ffffff;
struct turtle {
	int w, c;
} a[5610];
bool operator < (turtle x, turtle y) {
	if ( x.c == y.c )	return x.w < y.w;
	return x.c < y.c;
}
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int n = 1, ans = 1;
	while ( cin >> a[n].w >> a[n].c ) {
		a[n].c -= a[n].w;
		dp[n] = inf;
		n++;
	}
	n--;
	sort(a+1,a+n);
	for ( int i=1; i<=n; i++ ) {
		for ( int j=n; j>0; j-- ) {
			if ( a[i].c >= dp[j-1] )
				dp[j] = min(dp[j],dp[j-1]+a[i].w);
			if ( dp[j] < inf )
				ans = max(ans,j);
		}
	}
	return 0;
}

