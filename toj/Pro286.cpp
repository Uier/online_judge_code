#include <iostream>
#include <string.h>
#include <vector>
#define maxn 5001
using namespace std;
int arr[maxn], inedge[maxn];
bool v[maxn], edge[maxn][maxn];
vector<int> G[maxn];
int dfs(int x) {
	int s = 0;
	for ( int i : G[x] )
		s = max(s,dfs(i));
	return s+1;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for ( int i=0, x; i<m; ++i ) {
		cin >> x;
		for ( int j=0; j<x; ++j ) {
			cin >> arr[j];
			v[arr[j]] = true;
		}
		for ( int j=arr[0]; j<=arr[x-1]; ++j ) {
			if ( v[j] ) {
				v[j] = false;
				continue;
			}
			for ( int k=0; k<x; ++k ) {
				if ( edge[j][k] )	continue;
				edge[k][j] = edge[j][k] = 1;
				G[j].emplace_back(arr[k]);
				inedge[arr[k]]++;
			}
		}
	}
	int ans = 0;
	for ( int i=1; i<=n; ++i )
		if ( inedge[i] == 0 )
			ans = max(ans,dfs(i));
	cout << ans << '\n';
	return 0;
}

