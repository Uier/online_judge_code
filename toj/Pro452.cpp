#include <iostream>
#include <vector>
#define maxn 10005
using namespace std;
int n, m, q, bcc[maxn], cnt, D[maxn], L[maxn], dfn, R[maxn][maxn];
bool instk[maxn];
vector<int> G[maxn], stk;
void dfs(int x, int fa) {
	D[x] = L[x] = ++dfn;
	stk.emplace_back(x);
	instk[x] = true;
	for ( int i : G[x] )
		if ( !D[i] ) {
			dfs(i,x);
			L[x] = min(L[x],L[i]);
		} else if ( (i != fa || R[x][i] > 1) && instk[i] ) {
			L[x] = min(L[x],D[i]);
		}
	if ( D[x] == L[x] ) {
		int tmp;
		cnt++;
		do {
			tmp = stk.back();	stk.pop_back();
			instk[tmp] = false;
			bcc[tmp] = cnt;
		} while ( tmp != x );
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> q;
	int a, b;
	while ( m-- && cin >> a >> b ) {
		if ( a == b )	continue;
		G[a].emplace_back(b);
		G[b].emplace_back(a);
		R[a][b]++;
		R[b][a]++;
	}
	for ( int i=0; i<n; ++i )
		if ( !D[i] )
			dfs(i,i);
	while ( q-- && cin >> a >> b )
		cout << (bcc[a]==bcc[b] ? 'Y' : 'N') << '\n';
	return 0;
}

