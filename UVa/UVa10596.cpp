#include <iostream>
#include <vector>
#define maxn 205
using namespace std;
vector<int> G[maxn];
bool V[maxn];
void dfs(int x) {
	V[x] = 1;
	for ( int i : G[x] )
		if ( !V[i] )
			dfs(i);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	while ( cin >> n >> m ) {
		for ( int i=0; i<n; ++i ) {
			G[i].clear();
			V[i] = 0;
		}
		for ( int i=0, a, b; i<m; ++i ){
			cin >> a >> b;
			G[a].emplace_back(b);
			G[b].emplace_back(a);
		}
		if ( m == 0 ) {
			cout << "Not Possible\n";
			continue;
		}
		bool cnt = false;
		for ( int i=0; i<n; ++i )
			cnt |= G[i].size()&1;
		if ( cnt )	cout << "Not Possible\n";
		else {
			for ( int i=0; i<n; ++i )
				if ( G[i].size() ) {
					dfs(i);
					break;
				}
			bool flag = true;
			for ( int i=0; i<n; ++i )
				if ( G[i].size() && !V[i] )	flag = false;
			if ( flag )	cout << "Possible\n";
			else	cout << "Not Possible\n";
		}
	}
	return 0;
}

