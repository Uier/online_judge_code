#include <iostream>
#include <string.h>
#define int long long
#define LMT 2147483648
using namespace std;
int n, dp[205];
string s;
main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	while ( n-- ) {
		cin >> s;
		memset(dp,0,sizeof dp);
		for ( int i=1; i<=s.size(); i++ )
			for ( int j=1; j<=10&&j<=i; j++ ) {
				int sum = 0;
				for ( int k=0; k<j; k++ ) {
					sum = sum*10 + (s[i-j+k]-'0');
					if ( sum < LMT && sum >= 0 )
						dp[i] = max(dp[i],dp[i-j]+sum);
					else 
						break;
				}
			}
		cout << dp[s.size()] << '\n';
	}
	return 0;
}

