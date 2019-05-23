#include <iostream>
#define maxn 1005
using namespace std;
string G[maxn];
long long f[maxn][maxn];
int main() {
	ios::sync_with_stdio(false);
	//   sync_with_YinHsuan(true);
	cin.tie(0);
	int h, w, mod = 1e9+7;
	long long ans = 0;
	cin >> h >> w;
	for ( int i=0; i<h; ++i )
		cin >> G[i];
	f[0][0] = 1;
	for ( int i=1; i<w; ++i ) {
		if ( G[0][i] == '#' )	break;
		f[0][i] = f[0][i-1];
	}
	for ( int i=1; i<h; ++i ) {
		if ( G[i][0] == '#' )	break;
		f[i][0] = f[i-1][0];
	}
	for ( int i=1; i<h; ++i )
		for ( int j=1; j<w; ++j ) {
			if ( G[i-1][j] != '#' )	f[i][j] += f[i-1][j];
			if ( G[i][j-1] != '#' )	f[i][j] += f[i][j-1];
			f[i][j] %= mod;
		}
	cout << f[h-1][w-1] << '\n';
	return 0;
}

