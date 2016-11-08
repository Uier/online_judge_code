#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int t, n, m, a, b, c, d, p[1000002];
long long sum;
struct E {
    int u, v, cost;
} G[3000002];
bool cmp(E x, E y) {
    return x.cost < y.cost;
}
void init() {
    sum = 0;
    memset(G,0,sizeof G);
    for ( int i=0; i<=n; i++ )    p[i] = i;
}
int find(int x) {
    return (p[x]==x) ? x : (p[x]=find(p[x]));
}
void U(int x, int y) {
    p[find(y)] = find(x);
}
main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while ( t-- ) {
        cin >> n >> m;
        init();
        for ( int i=0; i<m; i++ ) {
            cin >> G[i].u >> G[i].v >> c >> d;
            G[i].cost = c-d;
        }
        sort(G,G+m,cmp);
        for ( int i=0; i<m; i++ ) {
            if ( find(G[i].u) != find(G[i].v) || G[i].cost < 0 ) {
                sum += G[i].cost;
                U(G[i].u,G[i].v);
            }
        }
        cout << sum << '\n';
    }
    return 0;
}

