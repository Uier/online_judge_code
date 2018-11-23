#include <iostream>
using namespace std;
int arr[11][11], tmp[11][11], oper[11];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int r, c, m;
	while ( cin >> r >> c >> m ) {
		for ( int i=1; i<=r; ++i )
			for ( int j=1; j<=c; ++j )
				cin >> arr[i][j];
		for ( int i=0; i<m; ++i )
			cin >> oper[i];
		for ( int k=m-1; k>=0; --k ) {
			for ( int i=1; i<=r; ++i )
				for ( int j=1; j<=c; ++j )
					tmp[i][j] = arr[i][j];
			if ( oper[k] == 0 ) {
				for ( int j=1; j<=c; ++j )
					for ( int i=1; i<=r; ++i )
						arr[c-j+1][i] = tmp[i][j];
				swap(r,c);
			} else {
				for ( int i=1; i<=r; ++i )
					for ( int j=1; j<=c; ++j )
						arr[r-i+1][j] = tmp[i][j];
			}
		}
		cout << r << ' ' << c << '\n';
		for ( int i=1; i<=r; ++i ) {
			for ( int j=1; j<=c; ++j ) {
				if ( j > 1 )	cout << ' ';
				cout << arr[i][j];
			}
			cout << '\n';
		}
	}
	return 0;
}

