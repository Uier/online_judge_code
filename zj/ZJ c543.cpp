#include <iostream>
#define maxn 100001
using namespace std;
long long dp[maxn][10], mod = 1000000007;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for ( int i=1; i<10; ++i )	dp[1][i] = i;
	for ( int i=2; i<maxn; ++i ) {
		dp[i][0] = dp[i-1][9];
		for ( int j=1; j<10; ++j )
			dp[i][j] = (dp[i][j-1]+dp[i-1][9]-dp[i-1][j-1]+mod)%mod;
	}
	string s;
	while ( cin >> s ) {
		int len = s.size();
		if ( len == 1 )	cout << s[0]-'0' << '\n';
		else {
			long long ans = 0;
			for ( int i=0; i<len; ++i ) {
				if ( i && s[i] < s[i-1] )	break;
				if ( s[i] == '0' )	continue;
				if ( i == 0 )	ans += dp[len-i][s[i]-'1'];
				else if ( i == len-1 )	ans += dp[len-i][s[i]-'0']-dp[len-i][s[i-1]-'1'];
				else	ans += dp[len-i][s[i]-'1']-dp[len-i][s[i-1]-'1'];
				ans = (ans+mod)%mod;
			}
			cout << ans << '\n';
		}
	}
	return 0;
}

