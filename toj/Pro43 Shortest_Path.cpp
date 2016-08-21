#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
#define maxn 10005
const long long INF=2000000000;
struct edge {
	int to, cost;
};
int n, m, st, ed;
bool inq[maxn];
long long d[maxn];
vector<edge> g[maxn];
queue<int> Q;
void bellman_ford() {
	while ( !Q.empty() )
		Q.pop(); 
	memset(inq, false, sizeof(inq));
	d[st] = 0;
	Q.push(st);
	inq[st] = true;
	while ( !Q.empty() ) {
		int u = Q.front();
		Q.pop();
		inq[u] = false;
		for ( edge i : g[u] )
			if ( d[u]<INF && d[i.to]>d[u]+i.cost ){
				d[i.to] = d[u]+i.cost;
				if ( !inq[i.to] ) {
					Q.push(i.to);
					inq[i.to] = true;
				}
			}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for ( int i=0; i<n; i++ ) d[i] = INF;
	while ( m-- ) {
		int a, b, c;
		cin >> a >> b >> c;
		g[a].push_back(edge{b,c});
		g[b].push_back(edge{a,c});
	}
	cin >> st >> ed;
	bellman_ford();	
	cout << d[ed] << endl;
	return 0;
}

