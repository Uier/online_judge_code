#include <iostream>
#define maxn 101
using namespace std;
int D[maxn][maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, a, b, c;
	while ( cin >> n && n ) {
		for ( int i=1; i<=n; ++i )
			for ( int j=i+1; j<=n; ++j )
				D[i][j] = D[j][i] = 2e9;
		for ( int i=1; i<=n; ++i ) {
			cin >> a;
			for ( int j=0; j<a; ++j ) {
				cin >> b >> c;
				D[i][b] = c;
			}
		}
		for ( int k=1; k<=n; ++k )
			for ( int i=1; i<=n; ++i )
				for ( int j=1; j<=n; ++j )
					if ( D[i][k] < 2e9 && D[k][j] < 2e9 )
						D[i][j] = min(D[i][j],D[i][k]+D[k][j]);
		int ans = 0, sum = 2e9, mx = 2e9, fail = 0;
		for ( int i=1; i<=n; ++i ) {
			int tmp1 = 0, tmp2 = 0;
			bool flag = false;
			for ( int j=1; j<=n; ++j ) {
				if ( D[i][j] == 2e9 ) {
					flag = true;
					break;
				}
				tmp1 += D[i][j];
				tmp2 = max(tmp2,D[i][j]);
			}
			if ( flag ) {
				fail++;
				continue;
			}
			if ( tmp1 < sum || (tmp1 == sum && tmp2 < mx) ) {
				ans = i;
				sum = tmp1;
				mx = tmp2;
			}
		}
		if ( fail == n )	cout << "disjoint\n";
		else	cout << ans << ' ' << mx << '\n';
	}
	return 0;
}

