#include <iostream>
#include <vector>
#include <string.h>
#define int long long
#define maxn 100005
using namespace std;
int arr[maxn], rans = maxn, vis[maxn];
vector<int> G[maxn];
void dfs(int x, int dep, int fa) {
	vis[x] = dep;
	for ( int i : G[x] ) {
		if ( i == fa )	continue;
		if ( vis[i] ) {
			if ( dep > vis[i]) {
				// cout << "x,i: " << x << ' ' << i << ' ' << dep << ' ' << vis[i] << '\n';
				rans = min(rans,dep-vis[i]+1);
			}
		} else {
			dfs(i,dep+1,x);
		}
	}
}
int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, inf = 1e18;
	cin >> n;
	// for ( int i=1; i<=n; ++i )	p[i] = i, sum[i] = 1;
	for ( int i=1; i<=n; ++i )	cin >> arr[i];
	int ans = n+1;
	for ( int i=1; i<=inf; i<<=1 ) {
		int cnt = 0;
		for ( int j=1; j<=n; ++j ) {
			if ( i&arr[j] ) {
				cnt++;
			}
		}
		if ( cnt >= 2 )	ans = min(ans,cnt);
	}
	// cout << "ans: " << ans << '\n';
	if ( ans == n+1 )	cout << -1 << '\n';
	else if ( ans > 2 )	cout << ans << '\n';
	else {
		for ( int i=1; i<=inf; i<<=1 ) {
			bool f = 1;
			int fir = 0;
			for ( int j=1; j<=n; ++j ) {
				if ( i&arr[j] ) {
					if ( f ) {
						f = 0;
						fir = j;
					} else {
						G[fir].emplace_back(j);
						G[j].emplace_back(fir);
						// cout << "fir,j: " << fir << ' ' << j << '\n';
					}
				}
			}
		}
		for ( int i=1; i<=n; ++i ) {
			// if ( vis[i] == 0 ) {
			memset(vis,0,sizeof(vis));
				dfs(i,1,i);
			// }
		}
		if ( rans == maxn )	cout << -1 << '\n';
		else	cout << rans << '\n';
	}
	return 0;
}