#include <iostream>
using namespace std;
int n, dp[3010][3010];
char r[3010];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> n;
    while ( n-- ) {
        cin >> s;
        for ( int i=0; i<s.size(); i++ )
            r[i] = s[s.size()-1-i];    
        dp[0][0] = 0;
        for ( int i=1; i<=s.size(); i++ )
            for ( int j=1; j<=s.size(); j++ )
                if ( s[i-1] == r[j-1] )
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        cout << dp[s.size()][s.size()] << '\n';
    }
    return 0;
}
