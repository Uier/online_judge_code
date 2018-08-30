#include <iostream>
#include <vector>
#include <string.h>
#define maxn 100005
using namespace std;
struct pair {
	int u, v;
} arr[maxn];
struct edge {
	int to, cost;
};
vector<edge> G[maxn];
int n, seg[maxn*4], path[maxn]; // path to fa
void modify(int l, int r, int x, int val, int d) {
	if ( x < l || x > r ) return;
	if ( l == r && l == x ) {
		seg[d] = val;
		return;
	}
	int mid = (l+r)/2;
	modify(l,mid,x,val,d*2);
	modify(mid+1,r,x,val,d*2+1);
	seg[d] = max(seg[d*2],seg[d*2+1]);
}
int query(int a, int b, int l, int r, int d) {
	if ( a > r || b < l )	return -1e9;
	if ( a <= l && r <= b )	return seg[d];
	int mid = (l+r)/2;
	return max(query(a,b,l,mid,d*2),query(a,b,mid+1,r,d*2+1));
}
int siz[maxn], mson[maxn], fa[maxn], dep[maxn];
void dfs(int x) {
	siz[x] = 1;
	mson[x] = -1;
	for ( auto i : G[x] )
		if ( i.to != fa[x] ) {
			fa[i.to] = x;
			path[i.to] = i.cost;
			dep[i.to] = dep[x]+1;
			dfs(i.to);
			if ( mson[x] == -1 || siz[i.to] > siz[mson[x]] )
				mson[x] = i.to;
			siz[x] += siz[i.to];
		}
}
int link[maxn], linktop[maxn], cnt;
void findlink(int x, int top) {
	link[x] = ++cnt;
	modify(1,n,cnt,path[x],1);
	linktop[x] = top;
	if ( mson[x] == -1 )	return;
	findlink(mson[x],top);
	for ( auto i : G[x] ) {
		if ( i.to == mson[x] || i.to == fa[x] )	continue;
		findlink(i.to,i.to);
	}
} 
int lca(int u, int v) {
	int tu = linktop[u], tv = linktop[v], ans = -1e9;
	while ( tu != tv )
		if ( dep[tu] < dep[tv] ) {
			ans = max(ans,query(link[tv],link[v],1,n,1));
			v = fa[tv];
			tv = linktop[v];
		} else {
			ans = max(ans,query(link[tu],link[u],1,n,1));
			u = fa[tu];
			tu = linktop[u];
		}
	if ( dep[u] > dep[v] )	swap(u,v);
	if ( u == v ) return ans;
	return max(ans,query(link[u]+1,link[v],1,n,1));
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
			cin >> arr[i].u >> arr[i].v >> c;
			G[arr[i].u].emplace_back(edge{arr[i].v,c});
			G[arr[i].v].emplace_back(edge{arr[i].u,c});
		}
		dfs(1);
		findlink(1,1);
		while ( cin >> s && s[0] != 'D' ) {
			cin >> a >> b;
			if ( s[0] == 'Q' )	cout << lca(a,b) << '\n';
			else {
				int u = arr[a].u, v = arr[a].v;
				if ( u != fa[v] )	swap(u,v);
				modify(1,n,link[v],b,1);
			}
		}
	}
	return 0;
}
