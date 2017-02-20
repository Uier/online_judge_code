#include <iostream>
#include <vector> 
#include <queue>
#include <string.h>
#define maxn 1000005
using namespace std;
struct edge {
	int to, cost;
};
vector<edge> G[maxn], R[maxn];
int N, M, D[maxn], inf;
long long ans;
bool fail;
priority_queue<edge> Q;
bool operator < (edge x, edge y) {
	return x.cost > y.cost;
}
void dijkstra(bool first) {
	Q.push(edge{1,0});
	while ( !Q.empty() ) {
		edge tmp = Q.top();	Q.pop();
		if ( tmp.cost > D[tmp.to] )	continue;
		for ( edge i : (first ? G[tmp.to] : R[tmp.to]) )
			if ( D[i.to] > D[tmp.to]+i.cost ) {
				D[i.to] = D[tmp.to]+i.cost;
				Q.push(edge{i.to,D[i.to]});
			}
	}
	for ( int i=1; i<=M; i++ ) {
		if ( D[i] == inf )
			fail = true;
		ans += D[i];
	}
}
main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> M >> N;
	int p, q, r;
	for ( int i=0; i<N; i++ ) {
		cin >> p >> q >> r;
		G[p].push_back(edge{q,r});
		R[q].push_back(edge{p,r});
	}
	memset(D,0x3f,sizeof D);
	inf = D[1];
	D[1] = 0;
	dijkstra(true);
	if ( !fail ) {
		memset(D,0x3f,sizeof D);
		D[1] = 0;
		dijkstra(false);
	}
	cout << (fail ? 0 : ans) << '\n';
	return 0;
}

