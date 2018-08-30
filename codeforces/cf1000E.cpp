#include <iostream>
#include <vector>
#define maxn 300005
using namespace std;
int D[maxn], L[maxn], bcc[maxn], cnt, dist[maxn];
vector<int> G[maxn], STK, T[maxn];
void dfs(int x, int fa, int dep) {
	D[x] = L[x] = dep;
	STK.emplace_back(x);
	for ( int i : G[x] )
		if ( D[i] == 0 ) {
			dfs(i,x,dep+1);
			L[x] = min(L[x],L[i]);
		} else if ( i != fa )
			L[x] = min(L[x],D[i]);
	if ( D[x] == L[x] ) {
		int tmp;
		do {
			tmp = STK.back();	STK.pop_back();
			bcc[tmp] = cnt;
		} while ( tmp != x );
		cnt++;
	}
}
void findpath(int x, int fa) {
	for ( int i : T[x] )
		if ( i != fa ) {
			dist[i] = dist[x]+1;
			findpath(i,x);
		}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, a, b;
	cin >> n >> m;
	while ( m-- && cin >> a >> b ) {
		G[a].emplace_back(b);
		G[b].emplace_back(a);
	}
	dfs(1,1,1);
	for ( int i=1; i<=n; ++i )
		for ( int j : G[i] ) {
			if ( bcc[i] == bcc[j] )	continue;
			T[bcc[i]].emplace_back(bcc[j]);
		}
	findpath(0,0);
	int pt = 0;
	for ( int i=1; i<cnt; ++i )
		if ( dist[i] > dist[pt] )	pt = i;
	dist[pt] = 0;
	findpath(pt,pt);
	for ( int i=0; i<cnt; ++i )
		if ( dist[i] > dist[pt] )	pt = i;
	cout << dist[pt] << '\n';
	return 0;
}

