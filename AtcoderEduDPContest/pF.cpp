#include <iostream>
#define maxn 3005
using namespace std;
int dp[maxn][maxn], tc[maxn][maxn];
int main() {
	ios::sync_with_stdio(false);
	//   sync_with_YinHsuan(true);
	cin.tie(0);
	string s, t;
	cin >> s >> t;
	int ls = s.size(), lt = t.size();
	for ( int i=1; i<=ls; ++i )
		for ( int j=1; j<=lt; ++j ) {
			if ( dp[i-1][j] > dp[i][j-1] ) {
				dp[i][j] = dp[i-1][j];
				tc[i][j] = 1;
			} else {
				dp[i][j] = dp[i][j-1];
				tc[i][j] = 3;
			}
			if ( s[i-1] == t[j-1] && dp[i-1][j-1]+1 > dp[i][j] ) {
				dp[i][j] = dp[i-1][j-1]+1;
				tc[i][j] = 2;
			}
		}
	int i = ls, j = lt;
	string ans = "";
	while ( i > 0 && j > 0 ) {
		if ( tc[i][j] == 1 ) {
			i--;
		} else if ( tc[i][j] == 2 ) {
			i--;
			j--;
			ans += s[i];
		} else {
			j--;
		}
	}
	for ( int i=0; i<ans.size(); ++i )	cout << ans[ans.size()-1-i];
	cout << '\n';
	return 0;
}

