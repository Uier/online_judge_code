#include <iostream>
#include <string.h>
using namespace std;
int L;
string s;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while ( cin >> s ) {
		L = s.size();
		int* dp = new int[L];
		memset(dp,-1,sizeof dp);
		for ( int i=1, j=-1; i<L; i++ ) {
			while ( j > -1 && s[i] != s[j+1] )	j = dp[j];
			if ( s[i] == s[j+1] )	dp[i] = ++j;
		}
		int ans = L-dp[L-1]-1;
		if ( L%ans )	cout << s;
		else
			for ( int i=0; i<ans; i++ )
				cout << s[i];
		cout << '\n';
		delete[] dp;
	}
	return 0;
}

