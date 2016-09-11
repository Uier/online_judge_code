#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
vector<int> G[100005];
pair<int,int> p={0,0};
bool V[100005];
void dfs(int x, int s) {
	if ( p.first <= s ) {
		p.first = s;
		p.second = x;
	}	
	for ( int i : G[x] )
		if ( !V[i] ) {
			V[i] = true;
			dfs(i, s+1);
		}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for ( int i=0; i<n; i++ )
		G[i].clear();
	while ( m-- ) {
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	memset(V, false, n);
	dfs(0,0);
	int q=p.second;
	p.first = 0;	p.second = 0;
	memset(V, false, n);
	dfs(q,0);
	cout << p.first << '\n';
	return 0;
}

