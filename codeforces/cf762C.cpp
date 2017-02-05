//	TLE
#include <iostream>
#include <vector>
using namespace std;
vector<int> G[100005];
vector<int> S;
int C[100005], root, ans;
bool F[100005], away;
void dfs(int x, int fa) {
//	cout << "fa: " << fa << " -> " << x << '\n';
	for ( int i : G[x] ) {
		if ( i != fa ) {
			dfs(i,x);
			if ( !F[i] && C[i] != C[x] && x != 1 ) {
				F[x] = true;
				S.push_back(x);
			}
		}
	}
}
void dfs2(int x, int fa) {
//	cout << "fa: " << fa << " -> " << x << '\n';
	for ( int i : G[x] ) {
		if ( i != fa ) {
			dfs2(i,x);
//			cout << "I: " << i << '\n';
			if ( C[i] != C[x] && x != root ) {
//				cout << "x: " << x << " i: " << i << " fa: "<< fa << '\n';
				away = false;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	for ( int i=0; i<100005; i++ )
		G[i].clear();
	S.clear();
	int n;
	cin >> n;
	for ( int i=1; i<n; i++ ) {
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for ( int i=1; i<=n; i++ )
		cin >> C[i];
	dfs(1,0);
	if ( S.empty() )
		ans = 1;
	else
		ans = -1;
	for ( int i : S ) {
		away = true;
		ans = -1;
		root = i;
		dfs2(i,0);
		cout << i << "'s res: " << away << '\n';
		if ( away ){
			ans = i;
			break;
		}
	}
	if ( ans != -1 )
		cout << "YES\n" << ans << '\n';
	else
		cout << "NO\n";
	return 0;
}

