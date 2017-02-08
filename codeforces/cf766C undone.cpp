#include <iostream>
#define MOD 1000000007
using namespace std;
//	dp[i][j] = solution for string[ i to j ];
int a[30], dp[1005][1005], c[30], f[1001]
long long ans[1001];
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	f[1] = 1;
	for ( int i=2; i<1001; i++ )
		f[i] = (f[i-1]%MOD)*i;
	int n;
	cin >> n;
	string s;
	cin >> s;
	for ( int i=0; i<26; i++ )
		cin >> a[i];
	for ( int i=0; i<s.size(); i++ ) {
		dp[i][i] = 1;
		memset(c,0,sizeof c);
		for ( int j=i+1; j<s.size(); j++ ) {
			c[s[i]-'a']++;
			if ( c[s[i]-'a'] > a[s[i]-'a'] )    break;
			
		}
	}
	int big = 0, small = 1000;
	for ( int i=0; i<s.size(); i++ ) {
		for ( int j=0; j<=i; j++ ) {
			ans[i]
		}
	}
	return 0;
}

