#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int k;
	string s;
	while ( cin >> k >> s ) {
		int row = 0, ans = 0;
		for ( int i=0; i+k<s.size(); i++ ) {
			( s[i] == s[i+k] ) ? (row+=1) : (row = 0);
			if ( row >= k )	ans++;
		}
		cout << ans << '\n';
	}
	return 0;
}

