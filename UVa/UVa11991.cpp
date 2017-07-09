#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
vector<int> G[1000005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, x, a, b;
	while ( cin >> n >> m ) {
		memset(G,0,sizeof G);
		for ( int i=1; i<=n; ++i ) {
			cin >> x;
			G[x].push_back(i);
		}
		while ( m-- ) {
			cin >> a >> b;
			cout << ((G[b].size() >= a) ? G[b][a-1] : 0 ) << '\n';
		}
	}
	return 0;
}

