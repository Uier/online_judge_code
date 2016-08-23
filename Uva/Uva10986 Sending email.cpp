#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
const ll INF=10000000000000;
struct edge {
	int to;
	ll cost;
};
int n, m, st, ed;
bool inq[20005];
queue<int> Q;
vector<edge> G[20005];
ll d[20005];
int main()
{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int t, x=0;
	cin >> t;
	while ( t-- ) {
		x++;
		cin >> n >> m >> st >> ed;
		for ( int i=0; i<n; i++ ) {
			d[i] = INF;
			G[i].clear();
			inq[i] = false;
		}
		while ( !Q.empty() )
			Q.pop();
		while ( m-- ) {
			int a, b, c;
			cin >> a >> b >> c;
			G[a].push_back({b,c});
			G[b].push_back({a,c});
		}
		for ( int i=0; i<n-1; i++ ) {
			d[st] = 0;
			Q.push(st);
			inq[st] = true;
			while ( !Q.empty() ) {
				int u = Q.front();
				Q.pop();
				inq[u] = false;
				for ( edge i : G[u] )
					if ( d[i.to] > d[u]+i.cost ) {
						d[i.to] = d[u]+i.cost;
						Q.push(i.to);
						inq[i.to] = true;
					}
			}
		}
		if ( d[ed] == INF )
			cout << "Case #" << x << ": " << "unreachable\n";
		else
			cout << "Case #" << x << ": " << d[ed] << '\n';
	}
	return 0;
}

