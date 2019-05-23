#include <iostream>
#include <string.h>
#define maxn 105
#define maxp 10005
using namespace std;
long long dp[maxp];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, p, x;
	while ( cin >> n >> p && n && p ) {
		memset(dp,0,sizeof(dp));
		dp[0] = 1;
		while ( n-- && cin >> x )
			for ( int j=0; j+x<=p; ++j )
				dp[j+x] += dp[j];
		cout << dp[p] << '\n';
	}
	return 0;
}

