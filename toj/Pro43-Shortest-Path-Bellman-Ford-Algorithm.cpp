#include <iostream>
#include <string.h>
using namespace std;
struct edge {
    int u, v, cost;
} G[20005];
int N, M, st, ed, D[10005];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
    cin >> N >> M;
    for ( int i=0; i<M*2; i+=2 ) {
        cin >> G[i].u >> G[i].v >> G[i].cost;
        G[i+1].v = G[i].u;	G[i+1].u = G[i].v;	G[i+1].cost = G[i].cost;
    }
    cin >> st >> ed;
    memset(D,0x3f,sizeof D);
    D[st] = 0;
    int INF = D[10003];
    for ( int k=0; k<N-1; ++k )
        for ( int i=0; i<M*2; ++i )
            if ( D[G[i].u] < INF )
                D[G[i].v] = min(D[G[i].v], D[G[i].u]+G[i].cost);
    cout << D[ed] << '\n';
    return 0;
}
