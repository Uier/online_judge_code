#include <iostream>
#include <vector>
#include <queue>
#define maxn 105
using namespace std;
struct edge {
	int to, cost;
};
struct node {
	int cur, cnt, rem;
} D[maxn];
int n, m, s, q, a, b, c;
vector<edge> G[maxn];
priority_queue<node,vector<node>,greater<node>> PQ;
bool operator > (node x, node y) {
	return x.cnt == y.cnt ? x.rem > y.rem : x.cnt < y.cnt;
}
void bfs(int x) {
	for ( int i=0; i<n; ++i )	D[i].cnt = n+1;
	D[x] = node{x,1,s};
	PQ.push(node{x,1,s});
	while ( !PQ.empty() ) {
		node tmp = PQ.top();	PQ.pop();
		x = tmp.cur;
		if ( tmp.cnt > D[x].cnt || (tmp.cnt == D[x].cnt && tmp.rem < D[x].rem) )	continue;
		for ( edge i : G[x] ) {
			int newcnt = tmp.cnt, newrem = tmp.rem;
			if ( i.cost >= s )	continue;
			else if ( i.cost < tmp.rem )	newrem -= i.cost;
			else	newcnt += 1, newrem = s-i.cost;
			if ( newcnt < D[i.to].cnt || (newcnt == D[i.to].cnt && newrem > D[i.to].rem) ) {
				D[i.to] = node{i.to,newcnt,newrem};
				PQ.push(D[i.to]);
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> s;
	for ( int i=0; i<m; ++i ) {
		cin >> a >> b >> c;
		G[a].emplace_back(edge{b,c});
		G[b].emplace_back(edge{a,c});
	}
	cin >> q;
	while ( q-- && cin >> a >> b ) {
		bfs(a);
		if ( D[b].cnt == n+1 )	cout << "Impossible\n";
		else	cout << D[b].cnt << '\n';
	}
	return 0;
}

