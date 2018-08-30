#include <iostream>
#include <vector>
#include <string.h>
#define maxn 100005
using namespace std;
int W[maxn], D[maxn], L[maxn], fa[maxn], bcc[maxn], cnt;
vector<int> G[maxn], stk, T[maxn];
void dfs1(int x, int dep) {
	D[x] = L[x] = dep;
	stk.emplace_back(x);
	for ( int i : G[x] )
		if ( D[i] == 0 ) { // tree edge
			fa[i] = x;
			dfs1(i,dep+1);
			L[x] = min(L[x],L[i]);
		} else if ( i != fa[x] ) // back edge
			L[x] = min(L[x],D[i]);
	if ( D[x] == L[x] ) {
		int tmp;
		do {
			tmp = stk.back();
			stk.pop_back();
			bcc[tmp] = cnt;
		} while ( tmp != x );
		cnt++;
	}
}
int ans = 1, tmp = 0, mn[maxn], hp[maxn];
void dfs2(int x, int pa) {
	for ( int i : T[x] )
		if ( i != pa ) {
			dfs2(i,x);
			hp[x] += hp[i];
			if ( x == bcc[0] )
				if ( hp[i] > tmp || (hp[i] == tmp && mn[i] < ans) ) {
					tmp = hp[i];
					ans = mn[i];
				}
		}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, a, b;
	cin >> n >> m;
	for ( int i=1; i<=n; ++i )	cin >> W[i];
	while ( m-- && cin >> a >> b ) {
		G[a].emplace_back(b);
		G[b].emplace_back(a);
	}
	dfs1(0,1);
	memset(mn,-1,sizeof(int)*cnt);
	for ( int i=0; i<=n; ++i ) {
		if ( mn[bcc[i]] == -1 || D[i] < D[mn[bcc[i]]] )
			mn[bcc[i]] = i;
		hp[bcc[i]] += W[i];
		for ( int j : G[i] )
			if ( bcc[i] != bcc[j] )
				T[bcc[i]].emplace_back(bcc[j]);
	}
	dfs2(bcc[0],-1);
	if ( fa[ans] != 0 && bcc[fa[ans]] == bcc[0] )
		cout << fa[ans] << '\n';
	else
		cout << ans << '\n';
	return 0;
}
