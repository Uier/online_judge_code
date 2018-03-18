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
bool V[maxn];
vector<edge> G[maxn];
priority_queue<edge> PQ;
bool operator < (edge x, edge y) {
	return x.cost > y.cost;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, a, b, c, cnt = 0, ans = 0;
	cin >> n >> m;
	for ( int i=0; i<m; ++i ) {
		cin >> a >> b >> c;
		G[a].emplace_back(edge{b,c});
		G[b].emplace_back(edge{a,c});
	}
	memset(D,0x3f,sizeof(D));
	D[0] = 0;
	PQ.push(edge{0,0});
	while ( !PQ.empty() ) {
		edge tmp = PQ.top();	PQ.pop();
		if ( V[tmp.to] )	continue;
		cnt++;
		V[tmp.to] = true;
		ans += tmp.cost;
		if ( cnt == n )	break;
		for ( edge i : G[tmp.to] )
			if ( !V[i.to] && i.cost < D[i.to] ) {
				D[i.to] = i.cost;
				PQ.push(edge{i.to,D[i.to]});
			}
	}
	cout << (cnt == n ? ans: -1) << '\n';
	return 0;
}

