#include <iostream>
#include <vector>
#define maxn 200005
using namespace std;
vector<int> G[maxn], ans;
int F[maxn];
void dfs(int x) {
	for ( int i : G[x] )
		if ( i != F[x] ) {
			F[i] = x;
			dfs(i);
		}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for ( int i=2, x; i<=n; ++i ) {
		cin >> x;
		G[x].emplace_back(i);
		G[i].emplace_back(x);
	}
	F[1] = -1;
	dfs(1);
	while ( n != -1 ) {
		ans.emplace_back(n);
		n = F[n];
	}
	for ( int i=0; i<ans.size(); ++i )	cout << ans[ans.size()-1-i] << ' ';
	cout << '\n';
	return 0;
}

