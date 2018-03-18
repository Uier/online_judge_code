#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define maxn 20005
#define maxm 130005
using namespace std;
struct mst {
	int u, v, w;
} T[maxm];
struct edge {
	int to, cost;
};
bool cmp(mst x, mst y) {
	return x.w < y.w;
}
vector<int> outofmst;
vector<edge> G[maxn];
int p[maxn], D[maxn], F[20][maxn], P[20][maxn];
int find(int x) {
	return (p[x]==x ? x : p[x]=find(p[x]));
}
void dfs(int x, int fa, int dep) {
	D[x] = dep;
	for ( edge i : G[x] ) 
		if ( i.to != fa ) {
			F[0][i.to] = x;
			P[0][i.to] = i.cost;
			dfs(i.to,x,dep+1);
		}
}
int LCA(int x, int y) {
	int maxpath = 0;
	if ( D[x] < D[y] )	swap(x,y);
	for ( int i=19; i>=0; --i )
		if ( F[i][x] != -1 && D[F[i][x]] >= D[y] ) {
			maxpath = max(maxpath,P[i][x]);
			x = F[i][x];
		}
	if ( x == y )	return maxpath;
	for ( int i=19; i>=0; --i )
		if ( F[i][x] != F[i][y] ) {
			maxpath = max(maxpath,max(P[i][x],P[i][y]));
			x = F[i][x], y = F[i][y];
		}
	return max(maxpath,max(P[0][x],P[0][y]));
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t, n, m;
	cin >> t;
	while ( t-- && cin >> n >> m ) {
		outofmst.clear();
		memset(G,0,sizeof(G));
		memset(F,-1,sizeof(F));
		memset(P,0,sizeof(P));
		for ( int i=0; i<m; ++i )
			cin >> T[i].u >> T[i].v >> T[i].w;
		sort(T,T+m,cmp);
		for ( int i=0; i<n; ++i )	p[i] = i;
		for ( int i=0; i<m; ++i ) {
			if ( find(T[i].u) == find(T[i].v) )	{
				outofmst.emplace_back(i);
				continue;
			}
			p[find(T[i].u)] = find(T[i].v);
			G[T[i].u].emplace_back(edge{T[i].v,T[i].w});
			G[T[i].v].emplace_back(edge{T[i].u,T[i].w});
		}
		dfs(0,-1,1);
		for ( int i=1; i<20; ++i )
			for ( int j=0; j<n; ++j )
				if ( F[i-1][j] != -1 ) {
					F[i][j] = F[i-1][F[i-1][j]];
					P[i][j] = max(P[i-1][j],P[i-1][F[i-1][j]]);
				}
		int ans = 2147483647;
		for ( int i=0; i<outofmst.size(); ++i ) {
			int x = outofmst[i];
			int maxpath = LCA(T[x].u,T[x].v);
			ans = min(ans,T[x].w-maxpath);
		}
		cout << ans << '\n';
	}
	return 0;
}
