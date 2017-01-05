#include <iostream>
#include <string.h>
using namespace std;
int dp[1003][1003];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	int x;
	cin >> x;
	string s, t;
	getline(cin,s);
	while ( x-- ) {
		getline(cin,s);
		t = "";
		for ( int i=s.size()-1; i>=0; i-- )
			t.push_back(s[i]);
		memset(dp,0,sizeof dp);
		for ( int i=1; i<=s.size(); i++ )
			for ( int j=1; j<=t.size(); j++ )
				if ( s[i-1] == t[j-1] )
					dp[i][j] = dp[i-1][j-1] + 1;
				else
					dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		cout << dp[s.size()][t.size()] << '\n';
	}
	return 0;
}

