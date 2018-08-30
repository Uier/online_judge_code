#include <iostream>
#define maxn 105
using namespace std;
int row[maxn], col[maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for ( int i=0; i<n; ++i )	cin >> row[i];
	for ( int i=0; i<m; ++i )	cin >> col[i];
	for ( int i=0; i<n; ++i ) {
		for ( int j=0; j<m; ++j ) {
			int xrow = 0;
			for ( int k=0; k<m; ++k ) {
				if ( k == j )	continue;
				xrow ^= col[k];
			}
			int ans = xrow^row[i];
			int tmp = ans;
			for ( int k=0; k<n; ++k ) {
				if ( k == i )	continue;
				tmp ^= row[k];
			}
			if ( tmp == col[j] ) {
				cout << "YES\n";
				for ( int k=0; k<n; ++k ) {
					for ( int l=0; l<m; ++l ) {
						if ( k == i && l == j )	cout << ans << ' ';
						else if ( k == i )	cout << col[l] << ' ';
						else if ( l == j )	cout << row[k] << ' ';
						else	cout << 0 << ' ';
					}
					cout << '\n';
				}
				return 0;
			}
		}
	}
	cout << "NO\n";
	return 0;
}

