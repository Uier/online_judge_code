#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int n;
bool vx[5005], vy[5005];
struct rook {
	int l, r, a;
	bool operator < (const rook& t) const {
		if ( rook.l == t.l )	return rook.r > t.r;
		return rook.l < t.l;
	}
} rx[5005], ry[5005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	while ( cin >> n && n ) {
		memset(vx,0,sizeof vx);
		memset(vy,0,sizeof vy);
		for ( int i=0; i<n; i++ ) {
			cin >> rx[i].l >> ry[i].l >> rx[i].r >> ry[i].r;
			rx[i].a = ry[i].a = 0;
		}
		sort(rx,rx+n,cmp);
		sort(ry,ry+n,cmp);
		for ( int i=0; i<n; i++ ) {
			for ( int j=rx[i].l; j<=rx[i].r; j++ )
				if ( !vx[j] )
					rx[i].a = j;
			for ( int j=ry[i].l; j<=ry[i].r; j++ )
				if ( !vy[j] )
					ry[i].a = j;
		}
		for ( int i=0; i<n; i++ )
			if ( !r
	}	
	return 0;
}

