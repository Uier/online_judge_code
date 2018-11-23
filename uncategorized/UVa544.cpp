#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define maxn 205
#define maxm 20005
using namespace std;
map<string,int> M;
struct edge {
	int u, v, cost;
} T[maxm];
struct mst {
	int to, cost;
};
vector<mst> G[maxn];
inline bool cmp(edge x, edge y) {
	return x.cost > y.cost;
}
int p[maxn], ans;
int find(int x) {
	return p[x]==x ? x : (p[x]=find(p[x]));
}
bool dfs(int x, int fa, int ed) {
	if ( x == ed )	return 1;
	for ( mst i : G[x] )
		if ( i.to != fa ) {
			if ( dfs(i.to,x,ed) ) {
				ans = min(ans,i.cost);
				return 1;
			}
		}
	return 0;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, cost, cnt, cs = 1;
	string s, t;
	while ( cin >> n >> m && (n||m) ) {
		M.clear();
		cnt = 1;
		ans = 2e9;
		for ( int i=0; i<m; ++i ) {
			cin >> s >> t >> cost;
			if ( M[s] == 0 )	M[s] = cnt++;
			if ( M[t] == 0 )	M[t] = cnt++;
			T[i] = edge{M[s],M[t],cost};
		}
		cin >> s >> t;
		sort(T,T+m,cmp);
		for ( int i=1; i<=n; ++i ) {
			p[i] = i;
			G[i].clear();
		}
		for ( int i=0; i<m; ++i ) {
			int tu = find(T[i].u), tv = find(T[i].v);
			if ( tu == tv )	continue;
			p[tu] = tv;
			G[T[i].u].emplace_back(mst{T[i].v,T[i].cost});
			G[T[i].v].emplace_back(mst{T[i].u,T[i].cost});
		}
		int ed = M[t];
		dfs(M[s],0,ed);
		cout << "Scenario #" << cs++ << '\n' << ans << " tons" << "\n\n";
	}
	return 0;
}

