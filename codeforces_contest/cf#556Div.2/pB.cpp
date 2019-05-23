#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string.h>
#include <cmath>
#define maxn 55
using namespace std;
typedef pair<int,int> pii;
int n;
char G[maxn][maxn];
void put(int i, int j) {
	if ( i+2 >= n || j-1 < 0 || j+1 >= n )	return;
	if ( G[i+1][j] == '#' || G[i+1][j-1] == '#' || G[i+1][j+1] == '#' || G[i+2][j] == '#' )	return;
	G[i][j] = G[i+1][j] = G[i+1][j-1] = G[i+1][j+1] = G[i+2][j] = '#';
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for ( int i=0; i<n; ++i )	for ( int j=0; j<n; ++j )	cin >> G[i][j];
	for ( int i=0; i<n; ++i )
		for ( int j=0; j<n; ++j )
			if ( G[i][j] == '.' )
				put(i,j);
	for ( int i=0; i<n; ++i )
		for ( int j=0; j<n; ++j )
			if ( G[i][j] == '.' )
				return cout << "NO\n", 0;
	cout << "YES\n";
	return 0;
}

