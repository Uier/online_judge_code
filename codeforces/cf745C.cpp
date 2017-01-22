#include <iostream>
#include <vector>
using namespace std;
int n, m, k, x, y, MXG, MX, c, gal, al, sum, ans;
bool g[1005], V[1005], gg;
vector<int> G[1005];
void dfs(int x) {
	c++;
	if ( g[x] )	gg = true;
	for ( int i : G[x] )
		if ( !V[i] ) {
			V[i] = true;
			dfs(i);
		}
}
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	cin >> n >> m >> k;
	for ( int i=0; i<k; i++ ) {
		cin >> x;
		g[x] = true;
	}
	for ( int i=0; i<m; i++ ) {
		cin >> x >> y;
		if ( g[x] )	g[y] |= g[x];
		else		g[x] |= g[y];
		G[x].push_back(y);
		G[y].push_back(x);
	}
	for ( int i=0; i<n; i++ )
		if ( !V[i] ) {
			c = 0;
			gg = false;
			V[i] = true;
			dfs(i);
			if ( gg && c == 1 )
				gal++;
			else if ( c == 1 )
				al++;
			else if ( gg ) {
				MXG = max(MXG,c);
				sum += (c*(c-1))/2;
			}
			else {
				MX = max(MX,c);
				sum += (c*(c-1))/2;
			}
		}
	if ( MXG==0 && MX==0 ) {
		if ( k )
			sum += (al*(al+1))/2;
		else
			sum += (al*(al-1))/2;
	}
	else if ( MXG == 0 )
		if ( k ) {
			sum -= (MX*(MX-1))/2;
			sum += (MX*(MX+1))/2;
		}
	else if ( MX == 0 )
		sum += (MXG+al*(MXG+al-1))/2;
	else if ( MXG > MX ) {
		sum += 
	}
	
	return 0;
}

