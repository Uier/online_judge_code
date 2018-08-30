#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#define maxn 300005
#define int long long
using namespace std;
typedef pair<int,int> pii;
struct edge {
	int to, cost;
};
vector<edge> G[maxn];
int n, m, D[maxn], rD[maxn], ans;
pii arr[maxn];
bool nb[maxn];
inline bool cmp(pii x, pii y) {
	if ( x.second == y.second )	return rD[x.first] > rD[y.first];
	return x.second < y.second;
}
void dfs(int x, int fa) {
	for ( edge i : G[x] )
		if ( i.to != fa ) {
			rD[i.to] = rD[x]+i.cost;
			dfs(i.to,x);
		}
}
main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for ( int i=1, x, y, z; i<n; ++i ) {
		cin >> x >> y >> z;
		G[x].emplace_back(edge{y,z});
		G[y].emplace_back(edge{x,z});
	}
	dfs(1,1);
	for ( int i=1; i<=n; rD[i]=0, ++i )	D[i] = rD[i];
	dfs(n,n);
	for ( int i=1; i<=n; ++i )	arr[i] = make_pair(i,D[i]-rD[i]);
	sort(arr+1,arr+1+n,cmp);
	for ( int i=1; i<=n; ++i ) {
		for ( edge j : G[arr[i].first] )	nb[j.to] = true;
		for ( int j=i+1; j<=n; ++j ) {
			if ( nb[arr[j].first] )	continue;
			ans = max(ans,D[arr[i].first]+rD[arr[j].first]);
			break;
		}
		for ( edge j : G[arr[i].first] )	nb[j.to] = false;
	}
	int x;
	while ( m-- && cin >> x )	cout << min(D[n],ans+x) << '\n';
	return 0;
}

