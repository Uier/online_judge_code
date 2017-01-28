#include <iostream>
#include <string.h>
using namespace std;
int dp[100][100];
char op[100][100];
string s, t;
void process(int x, int y, int z) {
	if ( !x && !y || !z )	return;
	if ( op[x][y] == 'D' ) {
		process(x-1,y,z-1);
		cout << z << " Delete " << y+1 << '\n';
	}
	else if ( op[x][y] == 'I' ) {
		process(x,y-1,z-1);
		cout << z << " Insert " << y << ',' << t[y-1] << '\n';
	}
	else if ( op[x][y] == 'R' ) {
		process(x-1,y-1,z-1);
		cout << z << " Replace " << y << ',' << t[y-1] << '\n';
	}
	else	process(x-1,y-1,z);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	bool ln = false;
	while ( getline(cin,s) && getline(cin,t) ) {
		if ( ln )	cout << '\n';
		else	ln = true;
		memset(dp,0,sizeof dp);
		for ( int i=0; i<=s.size(); i++ ) {
			dp[i][0] = i;
			op[i][0] = 'D';
		}
		for ( int i=0; i<=t.size(); i++ ) {
			dp[0][i] = i;
			op[0][i] = 'I';
		}
		for ( int i=1; i<=s.size(); i++ )
			for ( int j=1; j<=t.size(); j++ ) {
				if ( s[i-1] == t[j-1] ) {
					dp[i][j] = dp[i-1][j-1];
					op[i][j] = ' ';
				}
				else {
					dp[i][j] = min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1])) + 1;
					if ( dp[i][j] == dp[i-1][j] + 1 ) 
						op[i][j] = 'D';
					else if ( dp[i][j] == dp[i][j-1] + 1 ) 
						op[i][j] = 'I';
					else 
						op[i][j] = 'R';
				}
			}
//		cout << "dp operate table\n";
//		for ( int i=0; i<=t.size(); i++ ) {
//			for ( int j=0; j<=s.size(); j++ )
//				printf("%d %c\t", dp[j][i], op[j][i]);
//			printf("\n");
//		}
		cout << dp[s.size()][t.size()] << '\n';
		process(s.size(),t.size(),dp[s.size()][t.size()]);
	}
	return 0;
}

