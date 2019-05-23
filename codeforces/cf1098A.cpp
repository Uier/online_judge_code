#include <iostream>
#include <vector>
#define maxn 100005
using namespace std;
vector<int> G[maxn];
int val[maxn];
bool fail;
long long ans;
void dfs(int x, int fa, int dep) {
	int pre = -1;
	for ( int i : G[x] ) {
		if ( !(dep&1) )
			if ( val[i]-val[fa] < 0 )	fail = 1;
			else	pre = max(pre,val[i]-val[fa]);
		dfs(i,x,dep+1);
	}
	if ( !(dep&1) && pre != -1 )	ans += pre;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for ( int i=2, x; i<=n; ++i ) {
		cin >> x;
		G[x].emplace_back(i);
	}
	for ( int i=1; i<=n; ++i )	cin >> val[i];
	dfs(1,1,1);
	if ( fail )	cout << -1 << '\n';
	else	cout << ans+val[1] << '\n';
	return 0;
}

