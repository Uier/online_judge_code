#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#define maxn 1005
#define maxm 100005
#define logn 10
using namespace std;
int n, m, q, p[maxn], D[maxn], F[logn][maxn], FP[logn][maxn];
bool used[maxm];
struct edge {
	int u, v, cost, id;
} G[maxm];
struct tree {
	int to, cost;
};
vector<tree> T[maxn];
inline bool cmpcost(edge x, edge y)	{return x.cost < y.cost;}
inline bool cmpid(edge x, edge y) {return x.id < y.id;}
int find(int x) {return (p[x]==x ? x : (p[x]=find(p[x])));}
void dfs(int x, int f) {
	int sz = T[x].size();
	for ( int j=0; j<sz; ++j ) {
		tree i = T[x][j];
		if ( i.to == f )	continue;
		F[0][i.to] = x;
		FP[0][i.to] = i.cost;
		D[i.to] = D[x]+1;
		dfs(i.to,x);
	}
}
int LCA(int u, int v) {
	int maxpath = 0;
	if ( D[u] < D[v] )	swap(u,v);
	for ( int i=logn-1; i>=0; --i )
		if ( F[i][u] != -1 && D[F[i][u]] >= D[v] ) {
			maxpath = max(maxpath,FP[i][u]);
			u = F[i][u];
		}
	if ( u == v )	return maxpath;
	for ( int i=logn-1; i>=0; --i )
		if ( F[i][u] != F[i][v] ) {
			maxpath = max(maxpath,max(FP[i][u],FP[i][v]));
			u = F[i][u], v = F[i][v];
		}
	return max(maxpath,max(FP[0][u],FP[0][v]));
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> q;
	for ( int i=1; i<=m; ++i ) {
		cin >> G[i].u >> G[i].v >> G[i].cost;
		G[i].id = i;
	}
	sort(G+1,G+1+m,cmpcost);
	for ( int i=1; i<=n; ++i )	p[i] = i;
	for ( int i=1; i<=m; ++i ) {
		int tu = find(G[i].u), tv = find(G[i].v);
		if ( tu == tv )	continue;
		used[G[i].id] = true;
		p[tu] = tv;
		T[G[i].u].push_back(tree{G[i].v,G[i].cost});
		T[G[i].v].push_back(tree{G[i].u,G[i].cost});
	}
	memset(F,-1,sizeof(F));
	dfs(1,1);
	for ( int i=1; i<logn; ++i )
		for ( int j=1; j<=n; ++j )
			if ( F[i-1][j] != -1 ) {
				F[i][j] = F[i-1][F[i-1][j]];
				FP[i][j] = max(FP[i-1][j],FP[i-1][F[i-1][j]]);
			}
	sort(G+1,G+1+m,cmpid);
	for ( int i=0, id, x; i<q; ++i ) {
		cin >> id >> x;
		if ( used[id] )	cout << "Yes\n";
		else {
			if ( x <= LCA(G[id].u,G[id].v) )	cout << "Yes\n";
			else	cout << "No\n";
		}
	}
	return 0;
}

