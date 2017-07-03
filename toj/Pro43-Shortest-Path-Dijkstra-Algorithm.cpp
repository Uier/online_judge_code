#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;
struct edge {
	int to, cost;
};
int N, M, D[10005], st, ed;
vector<edge> G[10005];
priority_queue<int> Q;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for ( int i=0; i<M; ++i ) {
		int a, b, c;
		cin >> a >> b >> c;
		G[a].push_back({b,c});
		G[b].push_back({a,c});
	}
	cin >> st >> ed;
	memset(D,0x3f,sizeof D);
	int INF = D[0];
	D[st] = 0;
	Q.push(st);
	while ( !Q.empty() ) {
		int x = Q.top();	Q.pop();
		if ( D[x] == INF )	continue;
		for ( edge i : G[x] ) {
			if ( D[i.to] > D[x] + i.cost ) {
				D[i.to] = D[x] + i.cost;
				Q.push(i.to);
			}
		}
	}
	cout << D[ed] << '\n';
	return 0;
}

