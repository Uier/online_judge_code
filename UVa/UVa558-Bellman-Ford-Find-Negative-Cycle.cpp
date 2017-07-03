#include <iostream>
#include <string.h>
using namespace std;
int T, N, M, D[1005];
struct edge {
	int u, v, w;
} G[2005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while ( T-- ) {
		bool C = false;
		memset(G,0,sizeof G);
		memset(D,0x3f,sizeof D);
		cin >> N >> M;
		for ( int i=0; i<M; ++i )
			cin >> G[i].u >> G[i].v >> G[i].w;
		int INF = D[0];
		D[0] = 0;
		for ( int k=0; k<N-1; ++k )
			for ( int i=0; i<M; ++i )
				if ( D[G[i].u] < INF && D[G[i].v] > D[G[i].u]+G[i].w )
					D[G[i].v] = D[G[i].u] + G[i].w;
		for ( int i=0; i<M; ++i )
			if ( D[G[i].u] < INF && D[G[i].v] > D[G[i].u]+G[i].w )
				C = true;
		if ( C )	cout << "possible\n";
		else	cout << "not possible\n";
	}
	return 0;
}

