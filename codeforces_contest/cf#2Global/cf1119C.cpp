#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <string.h>
#include <map>
#define maxn 505
using namespace std;
bool S[maxn][maxn], T[maxn][maxn];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, x;
	cin >> n >> m;
	for ( int i=0; i<n; ++i )
		for ( int j=0; j<m; ++j ) {
			cin >> S[i][j];
		}
	for ( int i=0; i<n; ++i )
		for ( int j=0; j<m; ++j ) {
			cin >> x;
			T[i][j] = S[i][j]^x;
		}
	for ( int i=0; i<n; ++i ) {
		for ( int j=0; j<m; ++j ) {
			if ( T[i][j] ) {
				int k, l;
				for ( k=j+1; j<m; ++k ) {
					if ( T[i][k] )	break;
				}
				if ( k == m )	return cout << "No\n", 0;
				for ( l=i+1; l<n; ++l ) {
					if ( T[l][j] || T[l][k] )	break;
				}
				if ( l == n )	return cout << "No\n", 0;
				T[i][j] ^= 1;
				T[i][k] ^= 1;
				T[l][j] ^= 1;
				T[l][k] ^= 1;
			}
		}
	}
	for ( int i=0; i<n; ++i )
		for ( int j=0; j<m; ++j )
			if ( T[i][j] )
				return cout << "No\n", 0;
	cout << "Yes\n";
	return 0;
}

