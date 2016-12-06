#include <iostream>
#include <vector>
using namespace std;
struct edge {
	int to, cost;
};
bool flour[100005];
vector<edge> G[100005];
long long ans=1000000000000;
int main()
{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	// build graph 
	while ( m-- ) {
		int a, b, c;
		cin >> a >> b >> c;
		G[a].push_back({b,c});
		G[b].push_back({a,c});
	}
	while ( k-- ) { // mark the cities stored flour
		int a;
		cin >> a;
		flour[a] = true;
	}
	for ( int i=0; i<=n; i++ )
		if ( flour[i] ) // travel those cities' neighbor
			for ( edge j : G[i] ) // !flour[j.to] means bakery cannot open at the city stored flour
				if ( !flour[j.to] && j.cost < ans ) // choose the minimum cost
					ans = j.cost;
	if ( ans == 1000000000000 ) // the bakery was not exist so the cost was not replace the ans
		cout << -1 << '\n';
	else
		cout << ans << '\n'; // by uier
	return 0;
}

