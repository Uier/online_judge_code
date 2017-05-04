#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int k;
	string s;
	while ( cin >> k >> s ) {
		int seg = 0, ans = 0;
		for ( int i=0; i+k<s.size(); i++ ) {
			if ( s[i] == s[i+k] )
				seg++;
			else
				seg = 0;
			if ( seg >= k )	
				ans++;
		}
		cout << ans << '\n';
	}
	return 0;
}

