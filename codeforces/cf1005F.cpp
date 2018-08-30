#include <iostream>
#include <vector>
#include <queue>
#define maxn 200005
using namespace std;
struct edge {
	int to, id;
};
int n, m, k, D[maxn], V[maxn];
vector<edge> G[maxn];
vector<int> U[maxn];
vector<string> ans;
queue<int> Q;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for ( int i=0, x, y; i<m; ++i ) {
		cin >> x >> y;
		G[x].emplace_back(edge{y,i});
		G[y].emplace_back(edge{x,i});
	}
	D[1] = 1;
	Q.push(1);
	while ( !Q.empty() ) {
		int x = Q.front();	Q.pop();
		for ( edge i : G[x] )
			if ( !D[i.to] ) {
				D[i.to] = D[x]+1;
				U[i.to].emplace_back(i.id);
				Q.push(i.to);
			} else if ( D[x]+1 == D[i.to] )
				U[i.to].emplace_back(i.id);
	}
	while ( k-- ) {
		string tmp = "";
		for ( int i=0; i<m; ++i )	tmp.push_back('0');
		for ( int i=2; i<=n; ++i )	tmp[U[i][V[i]]] = '1';
		ans.emplace_back(tmp);
		bool flag = false;
		for ( int i=2; i<=n; ++i )
			if ( ++V[i] < U[i].size() ) {
				flag = true;
				break;
			} else V[i] = 0;
		if ( !flag )	break;
	}
	cout << ans.size() << '\n';
	for ( string i : ans )	cout << i << '\n';
	return 0;
}
