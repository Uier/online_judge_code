#include <iostream>
#include <vector>
#include <string.h>
#define maxn 2005
using namespace std;
vector<int> G[maxn];
vector<int> stack;
int D[maxn], L[maxn], scc = 0;
bool stacked[maxn];
void dfs(int x, int dep) {
	D[x] = L[x] = dep;
	stacked[x] = true;
	stack.emplace_back(x);
	for ( int i : G[x] ) {
		if ( D[i] ) L[x] = min(L[x],D[i]);
		else	dfs(i,dep+1);
 		if ( stacked[i] )
			L[x] = min(L[x],L[i]);
	}
	if ( D[x] == L[x] )	{
		while ( stack.back() != x )	stack.pop_back();
		stack.pop_back();
		scc++;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, M, a, b, c;
	while ( cin >> N >> M && N ) {
		for ( int i=1; i<=N; ++i )	G[i].clear();
		memset(D,0,sizeof(D));
		memset(L,0,sizeof(L));
		memset(stacked,false,sizeof(stacked));
		stack.clear();
		scc = 0;
		for ( int i=0; i<M; ++i ) {
			cin >> a >> b >> c;
			G[a].emplace_back(b);
			if ( c == 2 )	G[b].emplace_back(a);
		}
		for ( int i=1; i<=N; ++i ) if ( D[i] == 0 ) dfs(i,1);
		cout << (scc < 2 ? 1 : 0) << '\n';
	}
	return 0;
}