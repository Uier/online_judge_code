#include <iostream>
#include <vector>
#define maxn 50005
using namespace std;
int D[maxn], L[maxn], scc[maxn], cnt = 0, in[maxn];
bool instk[maxn];
vector<int> G[maxn], stk, city[maxn], dag[maxn];
void dfs(int x, int fa, int dep) {
	D[x] = L[x] = dep;
	stk.emplace_back(x);
	instk[x] = true;
	for ( int i : G[x] )
		if ( !D[i] ) { // tree edge
			dfs(i,x,dep+1);
			L[x] = min(L[x],L[i]);
		} else if ( i != fa && instk[i] ) // back edge
			L[x] = min(L[x],D[i]);
	if ( D[x] == L[x] ) {
		int tmp;
		do {
			instk[tmp=stk.back()] = false;
			stk.pop_back();
			scc[tmp] = cnt;
			city[cnt].emplace_back(tmp);
		} while( tmp != x );
		cnt++;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for ( int i=0, a, b; i<m; ++i ) {
		cin >> a >> b;
		G[a].emplace_back(b);
	}
	for ( int i=1; i<=n; ++i )	if ( D[i] == 0 )	dfs(i,i,1);
	int cap = 0, ans = 1e9, edge = 0;
	for ( int i=1; i<cnt; ++i )
		if ( city[i].size() > city[cap].size() )
			cap = i;
	for ( int i : city[cap] )
		ans = min(ans,i);
	for ( int i=1; i<=n; ++i )
		for ( int j : G[i] ) {
			int ni = scc[i], nj = scc[j];
			if ( ni == nj )	continue;
			dag[ni].emplace_back(nj);
			in[nj]++;
		}
	for ( int i=0; i<cnt; ++i )
		if ( in[i] == 0 && i != cap )
			edge++;
	cout << ans << ' ' << edge << '\n';
	return 0;
}
