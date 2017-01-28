#include <iostream>
using namespace std;
int G[8][8], brd[1000][8], temp[8], method = 0;
bool dx[8], dy[8], pos[15], neg[15];
void bt(int x) {
	if ( x == 8 ) {
		for ( int i=0; i<8; i++ )
			brd[method][i] = temp[i];
		method++;
		return;
	}
	//	bt is for x=0 x<8 x++
	for ( int j=0; j<8; j++ )
		if ( !dy[j] && !pos[x+j] && !neg[(x-j+15)%15] ) {
			dy[j] = pos[x+j] = neg[(x-j+15)%15] = true;
			temp[x] = j;
			bt(x+1);
			dy[j] = pos[x+j] = neg[(x-j+15)%15] = false;
		}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	bt(0);
	int t;
	cin >> t;
	while ( t-- ) {
		int ans = 0;
		for ( int i=0; i<8; i++ )
			for ( int j=0; j<8; j++ )
				cin >> G[i][j];
		for ( int i=0; i<method; i++ ) {
			int score = 0;
			for ( int j=0; j<8; j++ )
				score += G[j][brd[i][j]];
			ans = max(ans,score);
		}
		printf("%5d\n", ans);
	}
	return 0;
}

