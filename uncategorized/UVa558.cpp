#include <iostream>
#include <vector>
#include <string.h>
#define maxn 1005
using namespace std;
struct edge {
	int to, cost;
};
vector<edge> G[maxn];
int D[maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, n, m, a, b, c;
	cin >> t;
	while ( t-- && cin >> n >> m ) {
		for ( int i=0; i<n; ++i )	G[i].clear();
		memset(D,0x7f,sizeof(int)*n);
		while ( m-- && cin >> a >> b >> c )
			G[a].emplace_back(edge{b,c});
		bool update = false, ans = false;
		D[0] = 0;
		for ( int i=0; i<n; ++i ) {
			update = false;
			for ( int i=0; i<n; ++i )
				for ( edge j : G[i] )
					if ( D[j.to] > D[i]+j.cost ) {
						D[j.to] = D[i]+j.cost;
						update = true;
					}
			if ( !update )	break;
			if ( i == n-1 )	ans = true;
		}
		if ( ans )	cout << "possible\n";
		else	cout << "not possible\n";
	} 
	return 0;
}

