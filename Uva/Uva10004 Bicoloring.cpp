#include <iostream>
#include <vector>
using namespace std;
vector<int> g[205];
int vis[205];
bool dfs(int s, int color) {
	vis[s] = color;
	for ( int i : g[s] ) {
		if ( vis[i] == color )
			return false;
		if ( vis[i] == 0 )
			dfs(i, -color);
	}
	return true;
}
int main()
{
	int n, m;
	while ( cin >> n ) {
		if ( n==0 )
			break;
		for ( int i=0; i<205; i++ )	{
			vis[i] = 0;
			g[i].clear();
		}
		cin >> m;
		while ( m-- ) {
			int a, b;
			cin >> a >> b;
			g[a].push_back(b);
			g[b].push_back(a);			
		}
		vis[0] = 1;
		if ( dfs(0, -1) )
			cout << "BICOLORABLE.\n";
		else
			cout << "NOT BICOLORABLE.\n";
	}
	return 0;
}

