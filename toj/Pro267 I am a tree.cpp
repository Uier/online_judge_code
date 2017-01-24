#include <bits/stdc++.h>
#define mx 50005
using namespace std;
struct edge {
    int to, cost;
};
vector<edge> G[mx];
int D[mx][2];
int dfs(int x, int fa) {
	D[x][0] = 0;
	for ( edge i : G[x] )
		if ( i.to != fa )
			D[x][0] = max(D[x][0],dfs(i.to,x)+i.cost);
	return D[x][0];		
}
int main()  {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, ans=0;
    cin >> n;
    for ( int i=2; i<=n; i++ ) {
        int a, b;
        cin >> a >> b;
        G[i].push_back({a,b});
        G[a].push_back({i,b});
    }
    dfs(1,0);
    for ( int i=1; i<=n; i++ )
    	cout << i << ": " << D[i][0] << '\n';
    return 0;
}
