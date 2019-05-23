#include <iostream>
#include <vector>
#define maxn 300005
using namespace std;
struct node {
	int cur[3] = {0,0,0};
};
vector<int> G[maxn];
int cnt[3], col[maxn], cur[3], ans;
node dfs(int x, int fa) {
	int son = 0;
	node _new;
	for ( int i : G[x] )
		if ( i != fa ) {
			son++;
			node tmp = dfs(i,x);
			_new.cur[0] += tmp.cur[0];
			_new.cur[1] += tmp.cur[1];
			_new.cur[2] += tmp.cur[2];			
		}
	_new.cur[col[x]]++;
	if ( x != 1 ) {
		if ( col[x] == 1 ) { // red
			if ( cnt[1] == _new.cur[col[x]] && _new.cur[2] == 0 || cnt[2] == 0 ) {
//				cout << "x: " << x << '\n';
				ans++;
			}
		} else if ( col[x] == 2 ) { // blue
			if ( cnt[2] == _new.cur[col[x]] && _new.cur[1] == 0 || cnt[1] == 0 ) {
//				cout << "x: " << x << '\n';
				ans++;
			}
		} else { // uncol
			if ( cnt[1] == _new.cur[1] && _new.cur[2] == 0 || cnt[2] == _new.cur[2] && _new.cur[1] == 0 ) {
//				cout << "x: " << x<< '\n';
				ans++;
			}
		}
	}
	return _new;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for ( int i=1; i<=n; ++i ) {
		cin >> col[i];
		cnt[col[i]]++;
	}
	for ( int i=1, a, b; i<n; ++i ) {
		cin >> a >> b;
		G[a].emplace_back(b);
		G[b].emplace_back(a);
	}
	dfs(1,1);
	cout << ans << '\n';
	return 0;
}

