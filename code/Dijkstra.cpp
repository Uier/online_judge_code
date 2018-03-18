#include <iostream>
#include <vector>
#include <queue>
#define maxnm 10005 
using namespace std;
struct edge {
    int to, cost;
};
int n, m, D[maxnm], st, ed;
const int inf = 1e9;
vector<edge> G[maxnm];
priority_queue<edge> PQ;
bool operator < (edge x, edge y) {
    return x.cost > y.cost;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    int a, b, c;
    for ( int i=0; i<n; ++i ) D[i] = inf;
    for ( int i=0; i<m; ++i ) {
        cin >> a >> b >> c;
        G[a].emplace_back(edge{b,c});
        G[b].emplace_back(edge{a,c});
    }
    cin >> st >> ed;
    D[st] = 0;
    PQ.push(edge{st,0});
    while ( !PQ.empty() ) {
        edge x = PQ.top();    PQ.pop();
        if ( x.cost != D[x.to] )	continue;	// done
        for ( edge i : G[x.to] ) {
            if ( D[i.to] > D[x.to] + i.cost ) {
                D[i.to] = D[x.to] + i.cost;
                PQ.push(edge{i.to,D[i.to]});
            }
        }
    }
    cout << D[ed] << '\n';
    return 0;
}
