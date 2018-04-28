#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#define maxn 1005
using namespace std;
struct edge {
	int to, cost;
};
int D[maxn];
vector<edge> G[maxn];
priority_queue<edge> PQ;
bool operator < (edge x, edge y) {
	return x.cost < y.cost;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T, N, a, b, c;
	cin >> T >> N;
	memset(D,0x3f,sizeof(D));
	for ( int i=0; i<T; ++i ) {
		cin >> a >> b >> c;
		G[a].push_back(edge{b,c});
		G[b].push_back(edge{a,c});
	}
	D[1] = 0;
	PQ.push(edge{1,0});
	while ( !PQ.empty() ) {
		edge t = PQ.top();	PQ.pop();
		if ( t.cost > D[t.to] )	continue;
		int adj = G[t.to].size();
		for ( int j=0; j<adj; ++j ) {
			edge k = G[t.to][j];
			if ( D[t.to]+k.cost < D[k.to] ) {
				D[k.to] = D[t.to]+k.cost;
				PQ.push(edge{k.to,D[k.to]});
			}
		}
	}
	cout << D[N] << '\n';
	return 0;
}