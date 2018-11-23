#include <iostream>
#include <vector>
#define maxn 100005
using namespace std;
vector<int> G[maxn];
int D[maxn];
void dfs(int x, int fa) {
	for ( int i : G[x] )
		if ( i != fa ) {
			D[i] = D[x]+1;
			dfs(i,x);
		}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	while ( cin >> n ) {
		for ( int i=0; i<n; ++i )
			G[i].clear();
		for ( int i=1, a, b; i<n; ++i ){
			cin >> a >> b;
			G[a].emplace_back(b);
			G[b].emplace_back(a);
		}
		D[0] = 0;
		dfs(0,-1);
		int idx = 0;
		for ( int i=1; i<n; ++i )
			if ( D[i] > D[idx] )
				idx = i;
		D[idx] = 0;
		dfs(idx,-1);
		for ( int i=0; i<n; ++i )
			if ( D[i] > D[idx] )
				idx = i;
		cout << D[idx] << '\n';
	}
	return 0;
}

