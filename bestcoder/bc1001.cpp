#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while ( t-- ) {
		string s;
		cin >> s;
		int now=0;
		long long ans=0;
		for ( int i=0; i<s.size(); i++ ) {
			if ( s[i] == 'q' )
				ans += ++now;
			else
				now = 0;
		}
		cout << ans << '\n';
		ans = 0;
	} 
	return 0;
}

