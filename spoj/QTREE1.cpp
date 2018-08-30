#include <iostream>
#include <vector>
#include <string.h>
#define maxn 10005
using namespace std;
struct edge {
	int to, cost, id;
};
vector<edge> G[maxn];
int n, seg[maxn*4], D[maxn], fa[maxn], siz[maxn], mson[maxn], path[maxn];
void modify(int l, int r, int d, int x, int val) {
	if ( x > r || x < l ) return;
	if ( l == r && l == x ) {
		seg[d] = val;
		return;
	}
	int mid = (l+r)/2;
	modify(l,mid,d*2,x,val);
	modify(mid+1,r,d*2+1,x,val);
	seg[d] = max(seg[d*2],seg[d*2+1]);
}
int query(int a, int b, int l, int r, int d) {
	if ( a > r || b < l )	return -1;
	if ( a <= l && r <= b )	return seg[d];
	int mid = (l+r)/2;
	return max(query(a,b,l,mid,d*2),query(a,b,mid+1,r,d*2+1));
}
void dfs(int x) {
	siz[x] = 1;
	mson[x] = -1;
	for ( int i=0; i<G[x].size(); ++i ) {
		edge v = G[x][i];
		if ( v.to == fa[x] )	continue;
		D[v.to] = D[x]+1;
		fa[v.to] = x;
		path[v.to] = v.cost;
		dfs(v.to);
		if ( mson[x] == -1 || siz[v.to] > siz[G[x][mson[x]].to] )
			mson[x] = i;
		siz[x] += siz[v.to];
	}
}
int E[maxn], link[maxn], linktop[maxn], cnt;
void findlink(int x, int top, int index) {
	linktop[x] = top;
	E[index] = link[x] = ++cnt;
	modify(1,n,1,cnt,path[x]);
	if ( mson[x] == -1 )	return;
	findlink(G[x][mson[x]].to,top,G[x][mson[x]].id);
	for ( edge i : G[x] )
		if ( i.to != fa[x] && i.to != G[x][mson[x]].to )
			findlink(i.to,i.to,i.id);
}
int lca(int u, int v) {
	int tu = linktop[u], tv = linktop[v], ans = 0;
	while ( tu != tv ) {
		if ( D[tu] < D[tv] ) {
			swap(u,v);
			swap(tu,tv);
		}
		ans = max(ans,query(link[tu],link[u],1,n,1));
		tu = linktop[u=fa[tu]];
	}
	if ( D[u] > D[v] ) swap(u,v);
	return (u == v ? ans : max(ans,query(link[u]+1,link[v],1,n,1)));
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t, a, b, c;
	string s;
	cin >> t;
	while ( t-- && cin >> n ) {
		for ( int i=1; i<=n; ++i )	G[i].clear();
		memset(seg,0,sizeof(seg));
		cnt = 0;
		for ( int i=1; i<n; ++i ) {
			cin >> a >> b >> c;
			G[a].emplace_back(edge{b,c,i});
			G[b].emplace_back(edge{a,c,i});
		}
		dfs(1);
		findlink(1,1,0);
		while ( cin >> s && s[0] != 'D' && cin >> a >> b )
			if ( s[0] == 'C' )	modify(1,n,1,E[a],b);
			else cout << lca(a,b) << '\n';
	}
	return 0;
}
