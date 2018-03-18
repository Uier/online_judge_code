#include <stdio.h>
#include <vector>
#include <algorithm>
#define maxn 40005
using namespace std;
struct edge {
	int to, cost;
};
vector<edge> G[maxn];
int n, m, in[maxn], H[maxn*2], I[maxn*2], D[maxn], dp[20], s[20][maxn*2], tim;
void dfs(int x, int fa, int dep) {
	in[x] = tim;
	H[tim] = dep;
	I[tim++] = x;
	for ( int i=0; i<G[x].size(); ++i )
		if ( G[x][i].to != fa ) {
			D[G[x][i].to] = D[x] + G[x][i].cost;
			dfs(G[x][i].to,x,dep+1);
			H[tim] = dep;
			I[tim++] = x;
		}
}
int main() {
	int a, b, c;	char d;
	scanf("%d%d", &n, &m);
	for ( int i=0; i<m; ++i ) {
		scanf("%d%d%d %c", &a, &b, &c, &d);
		G[a].push_back(edge{b,c});
		G[b].push_back(edge{a,c});
	}
	dfs(1,0,0);
	dp[0] = 1;
	for ( int i=1; i<20; ++i )	dp[i] = dp[i-1]<<1;
	for ( int i=0; i<n*2-1; ++i )	s[0][i] = i;
	for ( int i=1; dp[i]<=n*2-1; ++i )
		for ( int j=0; j+dp[i]<=n*2-1; ++j )
			s[i][j] = (H[s[i-1][j]] < H[s[i-1][j+dp[i-1]]] ? s[i-1][j] : s[i-1][j+dp[i-1]]);
	scanf("%d", &a);
	while ( a-- ) {
		scanf("%d%d", &b, &c);
		int l = in[b], r = in[c];
		if ( l > r )	swap(l,r);
		int k = upper_bound(dp,dp+20,r-l+1)-dp-1;
		int idx = (H[s[k][l]] < H[s[k][r-dp[k]+1]] ? s[k][l] : s[k][r-dp[k]+1]);
		printf("%d\n", D[b]+D[c]-D[I[idx]]*2);
	}
	return 0;
}

