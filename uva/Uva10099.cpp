#include <iostream>
#include <vector>
using namespace std;
struct E {
	int to, cost;
};
vector<E> G[105];
int st, ed, ans;
bool V[105];
void dfs(int x, int sum) {
	V[x] = true;
	if ( x == ed )	ans = min(ans,sum);
	for ( E i : G[x] )
		if ( !V[i.to] )
			dfs(i.to,min(sum,i.cost));
}
main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	int n, m, tc = 0;
	while ( cin >> n >> m && n ) {
		for ( int i=1; i<=n; i++ ) {
			G[i].clear();
			V[i] = false;
		}
		for ( int i=0; i<m; i++ ) {
			int a, b, c;
			cin >> a >> b >> c;
			G[a].push_back(E{b,c});
			G[b].push_back(E{a,c});
		}
		int lm = 0;
		ans = 2e9;
		cin >> st >> ed >> lm;
		lm++;
		dfs(st,2e9);
		cout << "Scenario #" << ++tc << '\n';
		cout << "Minimum Number of Trips = ";
		if ( lm%ans )	cout << lm/ans+1 << '\n';
		else	cout << lm/ans << '\n';
		cout << '\n';
	}
	return 0;
}

