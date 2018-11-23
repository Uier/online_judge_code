#include <iostream>
#include <vector>
#define maxn 200005
using namespace std;
vector<int> G[maxn];
int S[maxn], F[maxn];
void dfs(int x, int dep) {
	if ( dep <= 2 )	S[x] = 1;
	for ( int i : G[x] ) {
		if ( i != F[x] ) {
			F[i] = x;
			dfs(i,dep+1);
		}
		if ( S[x] == 2 )	S[i] = max(S[i],1);
	}
	if ( S[x] == 0 ) {
		S[x] = 1;
		S[F[x]] = 2;
		S[F[F[x]]] = max(S[F[F[x]]],1);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for ( int i=1, a, b; i<n; ++i ) {
		cin >> a >> b;
		G[a].emplace_back(b);
		G[b].emplace_back(a);
	}
	dfs(1,0);
	int ans = 0;
	for ( int i=1; i<=n; ++i )	if ( S[i] == 2 )	ans++;
	cout << ans << '\n';
	return 0;
}

