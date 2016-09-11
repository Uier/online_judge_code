#include <iostream>
#include <vector>
using namespace std;
struct edge {
	int to, cost;
};
vector<edge> G[50005];
bool V[50005];
int w;
int dfs(int x, int s) {
	w = max(w,s);
	for ( edge i : G[x] )
		if ( !V[i.to] ) {
			V[i.to] = true;
			dfs(i.to,s+i.cost);
		}
	return w;
}
int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, ans=0;
	cin >> n;
	for ( int i=2; i<=n; i++ ) {
		int a, b;
		cin >> a >> b;
		G[i].push_back({a,b});
		G[a].push_back({i,b});
	}
	for ( int i=1; i<=n; i++ ) {
		for ( int j=1; j<=n; j++ )
			V[j] = false;
		V[i] = true;
		w = 0;
		ans ^= dfs(i,0);
	}
	cout << ans <<'\n';
	return 0;
}

