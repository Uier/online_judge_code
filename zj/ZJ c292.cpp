#include <iostream>
using namespace std;
int G[50][50], arr[50];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, d;
	cin >> n >> d;
	int x = n/2+1, y = n/2+1, pt = 0;
	for ( int i=0; i<50; ++i )	arr[i<<1] = arr[i<<1|1] = i+1;
	for ( int i=1; i<=n; ++i )
		for ( int j=1; j<=n; ++j )
			cin >> G[i][j];
	cout << G[x][y];
	int cnt = n*n-1;
	while ( cnt ) {
		if ( d == 0 ) { // left
			for ( int i=0; i<arr[pt]&&cnt; ++i, --cnt ) {
				y--;
				cout << G[x][y];
			}
			pt++;
			d++;
		} else if ( d == 1 ) {
			for ( int i=0; i<arr[pt]&&cnt; ++i, --cnt ) {
				x--;
				cout << G[x][y];
			}
			pt++;
			d++;
		} else if ( d == 2 ) {
			for ( int i=0; i<arr[pt]&&cnt; ++i, --cnt ) {
				y++;
				cout << G[x][y];
			}
			pt++;
			d++;
		} else {
			for ( int i=0; i<arr[pt]&&cnt; ++i, --cnt ) {
				x++;
				cout << G[x][y];
			}
			pt++;
			d++;
		}
		d %= 4;
	}
	cout << '\n';
	return 0;
}

