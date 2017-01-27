#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k, x=0;
	bool ans = true;
	string s;
	cin >> n;
	for ( int i=0; i<n; i++ ) {
		cin >> k >> s;
		if ( x == 0 && s[0] != 'S' )
			ans = false;
		else if ( x == 20000 && s[0] != 'N' )
			ans = false;
		if ( s[0] == 'S' ) {
			if ( x + k > 20000 )	ans = false;
			x += k;
		}
		else if ( s[0] == 'N' ) {
			if ( x - k < 0 )	ans = false;
			x -= k;
		}
	}
	if ( ans && x == 0 )
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}

