#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
int t, n, m, s, a, b, case_, mini, h[10005];
bool V[10005];
typedef pair<int,int> P;
queue<P> Q;
vector<int> G[10005];
int dfs(int x, int dep) {
	if ( h[x] == mini )
		return dep;
	int to = x;
	for ( int i=0; i<G[x].size(); i++ )
		if ( h[G[x][i]] < h[to] )
			to = G[x][i];
	if ( to == x )
		return -1;
	return dfs(to,dep+1);	
}
int bfs(int x) {
	Q.push({x,0});
	V[x] = true;
	while ( !Q.empty() ) {
		P p = Q.front();	Q.pop();
		if ( h[p.first] == mini )
			return p.second;
		for ( int i : G[p.first] )
			if ( !V[i] ) {
				V[i] = true;
				Q.push({i,p.second+1});
			}
	}
	return -1;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while ( t-- ) {
		cin >> n >> m >> s;
		mini = 10000000;
		while ( !Q.empty() )	Q.pop();
		for ( int i=0; i<n; i++ ) {		// init & input
			G[i].clear();
			V[i] = false;
			cin >> h[i];
			mini = min(h[i],mini);
		}
		while ( m-- ) {
			cin >> a >> b;
			G[a].push_back(b);
			G[b].push_back(a);
		}
		cout << "Case #" << ++case_ << ": ";
		int car=dfs(s,0), walk=bfs(s);
		if ( car == -1 && walk == -1 )
			cout << "Call 119!\n";
		else if ( car == -1 )
			cout << walk*6 << '\n';
		else
			cout << abs(walk*6-car) << '\n';
	}
	return 0;
}

