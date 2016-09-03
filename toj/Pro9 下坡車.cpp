#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
int h[10005], car, mini;
vector<int> G[10005];
typedef pair<int,int> P;
queue<P> Q;
bool V[10005];
int dfs(int x) {
	if ( h[x] == mini )
		return car;
	int to=x;
	for ( int i=0; i<G[x].size(); i++ )
		if ( h[G[x][i]] < h[to] )
			to = G[x][i];
	if ( to == x )
		return -1;
	car++;
	return dfs(to);	
}
int bfs(int x) {
	Q.push({x,0});
	V[x] = true;
	while ( !Q.empty() ) {
		P p=Q.front();	Q.pop();
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
	int t, n, m, s, a, b, x=1;
	cin >> t;
	while ( t-- ) {
		cin >> n >> m >> s;
		car = 0;
		mini = 10000000;
		while ( !Q.empty() )
			Q.pop();
		for ( int i=0; i<n; i++ ) {
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
		cout << "Case #" << x++ << ": ";
		int ad=dfs(s), ab=bfs(s);
		if ( ad == -1 && ab == -1 )
			cout << "Call 119!\n";
		else if ( ad == -1 )
			cout << ab*6 << '\n';
		else
			cout << abs(ab*6-ad)<< '\n';
	}
	return 0;
}

