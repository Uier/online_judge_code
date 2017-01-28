#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
typedef pair<int,int> R;
int n;
R ans[5005];
bool vx[5005], vy[5005], fail;
struct rook {
	int l, r, a, b, len;
	bool operator < (const rook& t) const {
		if ( r == t.r )	return len < t.len;
		else	return r < t.r;
	}
} rx[5005], ry[5005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	while ( cin >> n && n ) {
		fail = false;
		memset(ans,0,sizeof ans);
		memset(vx,0,sizeof vx);
		memset(vy,0,sizeof vy);
		for ( int i=0; i<n; i++ ) {
			cin >> rx[i].l >> ry[i].l >> rx[i].r >> ry[i].r;
			rx[i].a = ry[i].a = 0;
			rx[i].b = ry[i].b = i;
			rx[i].len = rx[i].r - rx[i].l;
			ry[i].len = ry[i].r - ry[i].l;
		}
		sort(rx,rx+n);
		sort(ry,ry+n);
//		cout << " RY \n";
//		for ( int i=0; i<n; i++ )
//			cout << ry[i].l << ' ' << ry[i].r << '\n';
		for ( int i=0; i<n; i++ ) {
			for ( int j=rx[i].l; j<=rx[i].r; j++ )
				if ( !vx[j] ) {
					rx[i].a = j;
					vx[j] = true;
					break;
				}
			for ( int j=ry[i].l; j<=ry[i].r; j++ )
				if ( !vy[j] ) {
					ry[i].a = j;
					vy[j] = true;
					break;
				}
		}
//		cout << " RX.a \n";
//		for ( int i=0; i<n; i++ )
//			cout << rx[i].a << '\n';
		for ( int i=0; i<n; i++ ) {
			if ( !rx[i].a || !ry[i].a )
				fail = true;
			ans[rx[i].b].first = rx[i].a;
			ans[ry[i].b].second = ry[i].a;
		}
//		cout << "\n ANS \n";
		if ( fail )
			cout << "IMPOSSIBLE\n";
		else
			for ( int i=0; i<n; i++ )
				cout << ans[i].first << ' ' << ans[i].second << '\n';
	}	
	return 0;
}

