#include <iostream>
#include <vector>
#define mx 50005
using namespace std;
typedef pair<int,int> pii;
struct edge {
    int to, cost;
};
vector<edge> G[mx];
struct data {
	pii one, two;
} D[mx];
int dfs_pre(int x, int fa) {
	for ( edge i : G[x] )
		if ( i.to != fa ) {
			int temp = dfs_pre(i.to,x) + i.cost;
			if ( temp > D[x].two.second )
				D[x].two.first = i.to, D[x].two.second = temp;
			if ( D[x].two.second > D[x].one.second )
				swap(D[x].one,D[x].two);
		}
	return D[x].one.second;
}
void dfs_ans(int x, int fa, int w) {
	for ( edge i : G[x] )
		if ( i.to != fa ) {
			if ( i.to != D[x].one.first ) {
				if ( D[i.to].one.second < D[x].one.second+i.cost ) {
					D[i.to].one.first = x;
					D[i.to].one.second = D[x].one.second+i.cost;
				} else if ( D[i.to].two.second < D[x].one.second+i.cost ) {
					D[i.to].two.first = x;
					D[i.to].two.second = D[x].one.second+i.cost;
				}
			} else if ( i.to != D[x].two.first ) {
				if ( D[i.to].one.second < D[x].two.second+i.cost ) {
					D[i.to].one.first = x;
					D[i.to].one.second = D[x].two.second+i.cost;
				} 
				else if ( D[i.to].two.second < D[x].two.second+i.cost ) {
					D[i.to].two.first = x;
					D[i.to].two.second = D[x].two.second+i.cost;
				}
			}
			dfs_ans(i.to,x,w+i.cost);
		}
}
int main()  {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for ( int i=2; i<=n; i++ ) {
        int a, b;
        cin >> a >> b;
        G[i].push_back({a,b});
        G[a].push_back({i,b});
    }
    dfs_pre(1,0);
	dfs_ans(1,0,0);
	int ans = D[1].one.second;
	for ( int i=2; i<=n; i++ )
		ans ^= D[i].one.second;
	cout << ans << '\n';
    return 0;
}

