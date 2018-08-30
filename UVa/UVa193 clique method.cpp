#include <iostream>
#include <string.h>
#define maxn 101
using namespace std;
// time complexity: O( 3^(n/3) )
int t, n, m, cnt;
bool G[maxn][maxn], ans[maxn];
struct sets {
	int sz = 0;
	bool s[maxn];
};
sets intersect(sets tmp, int x) { // 取交集 
	for ( int i=1; i<=n; ++i )
		if ( tmp.s[i] && !G[x][i] ) { // remove nodes that dont intersect
			tmp.s[i] = false;
			tmp.sz--;
		}
	return tmp;
}
void backtrack(sets R, sets P, sets X) {
	if ( P.sz == 0 ) {
		if ( X.sz == 0 ) {
			if ( R.sz > cnt ) {
				cnt = R.sz;
				for ( int i=1; i<=n; ++i )
					ans[i] = R.s[i];
			}
		}
		return;
	}
	int pivot;
	for ( pivot=1; pivot<=n; ++pivot )
		if ( P.s[pivot] || X.s[pivot] )
			break;
	for ( int i=1; i<=n; ++i )
		if ( P.s[i] && !G[pivot][i] ) {
			R.s[i] = true;	R.sz++;
			backtrack(R,intersect(P,i),intersect(X,i));
			R.s[i] = false;	R.sz--;
			P.s[i] = false;	P.sz--;
			if ( !X.s[i] ) {
				X.s[i] = true;
				X.sz++;
			}
		}
}
void solve() {
	// ensure no self-loop
	for ( int i=1; i<=n; ++i )	G[i][i] = false;
	
	sets R, P, X;
	/*
		R: 當前的clique
		P: nodes that connected with clique, waiting for backtrack
		X: used nodes
	*/
	// initial
	for ( int i=1; i<=n; ++i ) {
		R.s[i] = false;
		P.s[i] = true;
		X.s[i] = false;
	}
	R.sz = 0;
	P.sz = n;
	X.sz = 0;
	
	backtrack(R,P,X);
	cout << cnt << '\n';
	for ( int i=1, j=1; i<=n; ++i )
		if ( ans[i] ) {
			cout << i;
			if ( j == cnt )	cout << '\n';
			else	cout << ' ';
			j++;
		}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while ( t-- && cin >> n >> m ) {
		cnt = 0;
		memset(G,true,sizeof(G));
		memset(ans,false,sizeof(ans));
		for ( int i=0, x, y; i<m; ++i ) {
			cin >> x >> y;
			G[x][y] = G[y][x] = 0; // 補圖 
		}
		solve();
	}
	return 0;
}

