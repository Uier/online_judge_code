#include <iostream>
#include <vector>
using namespace std;
struct edge {
    int to, cost;    
};
vector<edge> g[10000];
int sum=0, minE=0, maxE=0;
bool vis[10000];
bool dfs(int s, int sum) {
    vis[s] = true;
    if ( sum >= minE && sum <= maxE )
        return true;
    for ( edge i : g[s] )
        if ( !vis[i.to] && dfs(i.to,sum+i.cost) )
	        return true;
    return false;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n >> minE >> maxE;
    while ( --n ) {
        int a, b, x;
        cin >> a >> b >> x;
        g[a].push_back({b,x});
        g[b].push_back({a,x});
    }
    if ( dfs(0,0) )
        cout << "Eat Eat Eat\n";
    else
        cout << "Go find other chickens\n";
    return 0;
}

