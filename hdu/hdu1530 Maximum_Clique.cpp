#include <iostream>
#define maxn 51
using namespace std;
struct sets {
	bool s[maxn];
	int sz;
};
int n, ans;
bool G[maxn][maxn];
sets intersect(sets tmp, int x) {
	for ( int i=0; i<n; ++i )
		if ( tmp.s[i] && !G[x][i] ) {
			tmp.s[i] = false;
			tmp.sz--;
		}
	return tmp;
}
void backtracking(sets R, sets V, sets X) {
	if ( V.sz == 0 ) {
		if ( X.sz == 0 )
			ans = max(ans,R.sz);
		return;
	}
	int pivot = 0;
	for ( ; pivot<n; ++pivot )
		if ( V.s[pivot] || X.s[pivot] )
			break;
	for ( int i=0; i<n; ++i )
		if ( V.s[i] && !G[pivot][i] ) {
			R.s[i] = true;	R.sz++;
			backtracking(R,intersect(V,i), intersect(X,i));
			R.s[i] = false;	R.sz--;
			V.s[i] = false;	V.sz--;
			if ( !X.s[i] ) {
				X.s[i] = true;	X.sz++;
			}
		}
}
void solve() {
	for ( int i=0; i<n; ++i )	G[i][i] = false;
	sets R, V, X;
	for ( int i=0; i<n; ++i ) {
		R.s[i] = false;
		V.s[i] = true;
		X.s[i] = false;
	}
	R.sz = 0;
	V.sz = n;
	X.sz = 0;
	ans = 0;
	backtracking(R,V,X);
	cout << ans << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	while ( cin >> n && n ) {
		for ( int i=0; i<n; ++i )
			for ( int j=0; j<n; ++j ) {
				cin >> G[i][j];
				G[j][i] = G[i][j];
			}
		solve();
	}
	return 0;
}

