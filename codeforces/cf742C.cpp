#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
int n, a, D, E, G[105], ans;
bool V[105], cnt;
void dfs(int x) {
	if ( !V[G[x]] ) {
		V[G[x]] = true;
		D++;
		dfs(G[x]);
	}
	else if ( G[x] != E )
		cnt = false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for ( int i=1; i<=n; i++ ) {
		cin >> a;
		G[i] = a;
	}
	cnt = ans = 1;
	for ( int i=1; i<=n; i++ ) {
		memset(V,false,sizeof V);
		V[i] = true;
		E = i;
		dfs(i);
	}
	if ( !cnt )	cout << -1 << '\n';
	else {
		memset(V,false,sizeof V);
		for ( int i=1; i<=n; i++ )
			if ( !V[i] ) {
				D = 1;
				V[i] = true;
				dfs(i);
				if ( D%2 == 0 )
					D /= 2;
				int k = __gcd(D,ans);
				ans = D*(ans/k);
			}
		cout << ans << '\n';
	}
	return 0;
}
