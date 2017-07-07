#include <iostream>
#include <string.h>
using namespace std;
int N, C = 1;
struct Matrix {
	long long l, r, cost;
} dp[15][15];
struct Path {
	int lx, ly, rx, ry;
} tg[15][15];
long long mul(int a, int b, int c, int d) {
	return dp[a][b].l*dp[a][b].r*dp[c][d].r+dp[a][b].cost+dp[c][d].cost;
}
void trace(int l, int r) {
	if ( l == r ) {
		cout << 'A' << l+1;
		return;
	}
	cout << '(';
	trace(tg[l][r].lx,tg[l][r].ly);
	cout << " x ";
	trace(tg[l][r].rx,tg[l][r].ry);
	cout << ')';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	while ( cin >> N && N ) {
		memset(dp,0x3f,sizeof dp);
		memset(tg,0,sizeof tg);
		for ( int i=0; i<N; ++i ) {
			cin >> dp[i][i].l >> dp[i][i].r;
			dp[i][i].cost = 0;
		}
		for ( int k=2; k<=N; ++k )
			for ( int i=0; i+k-1<N; ++i )
				for ( int j=i; j<i+k-1; ++j ) {
					long long tmp = mul(i,j,j+1,i+k-1);
					if ( tmp < dp[i][i+k-1].cost ) {
						dp[i][i+k-1].l = dp[i][j].l;
						dp[i][i+k-1].r = dp[j+1][i+k-1].r;
						dp[i][i+k-1].cost = tmp;
						tg[i][i+k-1].lx = i;
						tg[i][i+k-1].ly = j;
						tg[i][i+k-1].rx = j+1;
						tg[i][i+k-1].ry = i+k-1;
					}
				}
		cout << "Case " << C++ << ": ";
		trace(0,N-1);
		cout << '\n';
	}
	return 0;
}

