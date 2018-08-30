#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, ans = 0;
	string s, t;
	cin >> n >> s >> t;
	for ( int i=0; i<(n+1)/2; ++i ) {
		if ( i == n-1-i ) {
			if ( s[i] != t[i] )	ans++;
		} else {
			if (
			   ( s[i] == t[i] && s[n-1-i] == t[n-1-i] )
			|| ( s[n-1-i] == t[i] && s[i] == t[n-1-i] )	
			|| ( s[i] == s[n-1-i] && t[i] == t[n-1-i] ) )
				continue;
			if ( s[i] != s[n-1-i] && t[i] == t[n-1-i] )
				ans++;
			else if ( s[i] != t[i] && s[n-1-i] != t[n-1-i] && s[i] != t[n-1-i] && s[n-1-i] != t[i] )
				ans += 2;
			else
				ans++;
		}
	}
	cout << ans << '\n';
	return 0;
}

