#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#define maxn 1000005
using namespace std;
int n, m, D[maxn];
struct edge {
	int to, cost;
};
bool operator < (edge x, edge y) {
	return x.cost > y.cost;
}
vector<edge> G[2][maxn];
priority_queue<edge> PQ;
inline long long dijk(int id) {
	memset(D,0x3f,sizeof(D));
	D[1] = 0;
	PQ.push(edge{1,0});
	while ( !PQ.empty() ) {
		edge x = PQ.top();	PQ.pop();
		if ( x.cost > D[x.to] )	continue;
		for ( edge i : G[id][x.to] )
			if ( D[i.to] > D[x.to] + i.cost )
				PQ.push(edge{i.to,D[i.to]=D[x.to]+i.cost});
	}
	long long ans = 0;
	for ( int i=2; i<=n; ++i )	ans += D[i];
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for ( int i=0, a, b, c; i<m; ++i ) {
		cin >> a >> b >> c;
		G[0][a].emplace_back(edge{b,c});
		G[1][b].emplace_back(edge{a,c});
	}
	cout << dijk(0)+dijk(1) << '\n';
	return 0;
}
