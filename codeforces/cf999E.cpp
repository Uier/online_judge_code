#include <iostream>
#include <vector>
#include <set>
#define maxn 5005
using namespace std;
int cnt = 1, in[maxn], add[maxn], vis = 1, contri;
vector<int> G[maxn], D[maxn];
bool V[maxn];
set<int> SE;
void dfs(int x) {
	V[x] = true;
	for ( int i : G[x] ) {
		if ( !V[i] ) {
			cnt++;
			dfs(i);
		}
	}
}
void dfs2(int x) {
	add[x] = vis;
	for ( int i : G[x] ) {
		if ( !V[i] && add[i] != vis ) {
			contri++;
			dfs2(i);
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, s, a, b, maxin = 0;
	cin >> n >> m >> s;
	for ( int i=0; i<m; ++i ) {
		cin >> a >> b;
		in[b]++;
		G[a].emplace_back(b);
	}
	dfs(s);
	int ans = 0;
	while ( cnt < n ) {
		int mxcon = 0, index = 0;
		for ( int i=1; i<=n; ++i ) {
			if ( V[i] )	continue;
			contri = 0;
			dfs2(i);
			if ( contri >= mxcon ) {
				mxcon = contri;
				index = i;
			}
			vis++;
		}
		cnt++;
		ans++;
		dfs(index);
	}
//	for ( int i=1; i<=n; ++i ) {
//		D[in[i]].emplace_back(i);
//		maxin = max(maxin,in[i]);
//	}
//	for ( int i=0; i<=maxin; ++i ) {
//		if ( cnt == n )	break;
//		for ( int j : D[i] ) {
//			if ( V[j] )	continue;
//			if ( cnt == n )	break;
//			cnt++;
//			ans++;
//			dfs(j);
//		}
//	}
	cout << ans << '\n';
	return 0;
}
