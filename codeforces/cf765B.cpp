#include <iostream>
using namespace std;
bool a[300];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	bool ans = false;
	cin >> s;
	if ( s[0] != 'a' )	ans = true;
	a[s[0]] = true;
	for ( int i=1; i<s.size(); i++ ) {
		if ( !a[s[i]-1] && s[i] != 'a' ) {
			ans = true;
			break;
		}
		a[s[i]] = true;
	}
	cout << ((ans) ? "NO\n" : "YES\n");
	return 0;
}

