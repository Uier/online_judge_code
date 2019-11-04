#include <iostream>
#include <queue>
#include <string.h>
#define maxn 105
using namespace std;
int G[maxn][maxn], R[maxn][maxn], F[maxn];
bool vis[maxn];
bool bfs(int n, int s, int t) {
	queue<int> Q;
	Q.push(s);
	memset(vis,0,sizeof(vis));
	vis[s] = true;
	while ( !Q.empty() ) {
		int u = Q.front();	Q.pop();
		for ( int v=1; v<=n; ++v ) {
			if ( vis[v] || G[u][v]-R[u][v] <= 0 )	continue;
			vis[v] = true;
			F[v] = u;
			if ( v == t )	return true;
			Q.push(v);
		}
	}
	return false;
}
int maxflow(int n, int s, int t) {
	int ans = 0, mn;
	while ( bfs(n,s,t) ) {
		mn = 2e9;
		for ( int i=t; i!=s; i=F[i] )
			mn = min(mn,G[F[i]][i]-R[F[i]][i]);
		ans += mn;
		for ( int i=t; i!=s; i=F[i] ) {
			R[F[i]][i] += mn;
			R[i][F[i]] -= mn;
		}
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int cs = 1, n, m, s, t;
	while ( cin >> n && n ) {
		memset(G,0,sizeof(G));
		memset(R,0,sizeof(R));
		cin >> s >> t >> m;
		for ( int i=0, u, v, w; i<m; ++i ) {
			cin >> u >> v >> w;
			G[u][v] += w;
			G[v][u] += w;
		}
		cout << "Network " << cs++ << "\nThe bandwidth is " << maxflow(n,s,t) << ".\n\n";
	}
	return 0;
}

