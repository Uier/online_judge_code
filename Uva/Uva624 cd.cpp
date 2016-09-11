#include <iostream>
#include <stack>
#include <string.h>
using namespace std;
int v, n, w[20], p[20];
stack<int> S;
int main()
{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	while ( cin >> v >> n ) {
		int dp[v+1];
		bool ans[n][v+1];
		memset(dp,0,sizeof(dp));
		memset(ans,false,sizeof(ans));
		for ( int i=0; i<n; i++ ) {
			cin >> w[i];
			p[i] = w[i];
		}
		for ( int i=0; i<n; i++ )
			for ( int j=v; j>=w[i]; j-- )
				if ( dp[j] < dp[j-w[i]]+p[i] ) {
					dp[j] = dp[j-w[i]]+p[i];
					ans[i][j] = true;
				}
		for ( int i=n-1, j=dp[v]; i>=0; i-- )
			if ( ans[i][j] ) {
				S.push(w[i]);
				j -= w[i];
			}
		while ( !S.empty() ) {
			cout << S.top() << ' ';
			S.pop();
		}
		cout << "sum:" << dp[v] << '\n';
	}
	return 0;
}

