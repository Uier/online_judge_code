/*
fail(TLE)
		by uier
*/
#include <iostream>
#include <string.h>
#include <set>
#include <vector>
using namespace std;
set<int> s;
int p[50010];
vector<int> g[50010];
void dfs(int s, int x) {
	p[s] = x;
	for ( int i : g[s] )
		if ( p[i] == i )
			dfs(i,x);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, x=0;
	while ( cin >> n >> m ) {
		if ( n == 0 )
			break;
		x++;
		s.clear();
		for ( int i=1; i<=n; i++ ) {
			g[i].clear();
			p[i] = i;
		}
		while ( m-- )
		{
			int a, b;
			cin >> a >> b;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		for ( int i=1; i<=n; i++ )
			if ( p[i] == i )
				dfs(i,i);
		for ( int i=1; i<=n; i++ )
			s.insert(p[i]);
		cout << "Case " << x << ": " << s.size() << '\n';
	}
	return 0;
}

