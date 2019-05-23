#include <bits/stdc++.h>
#define maxn 101
using namespace std;
int front[maxn], _left[maxn], top[maxn][maxn];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, h;
	cin >> n >> m >> h;
	for ( int i=0; i<m; ++i )	cin >> front[i];
	for ( int i=0; i<n; ++i )	cin >> _left[i];
	for ( int i=0; i<n; ++i ) {
		for ( int j=0; j<m; ++j ) {
			cin >> top[i][j];
			if ( top[i][j] )	top[i][j] = front[j];
		}
	}
	for ( int i=0; i<n; ++i ) {
		for ( int j=0; j<m; ++j ) {
			if ( top[i][j] ) {
				if ( top[i][j] > _left[i] )	top[i][j] = _left[i];
			}
			cout << top[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}

