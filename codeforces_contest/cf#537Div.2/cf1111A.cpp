#include <iostream>
using namespace std;
bool is(char x) {
	if ( x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' )
		return true;
	return 0;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s, t;
	cin >> s >> t;
	int n = min(s.size(),t.size());
	bool fail = false;
	for ( int i=0; i<n; ++i ) {
		if ( is(s[i]) != is(t[i]) )	fail = true;
	}
	if ( fail || s.size() != t.size() )	cout << "No\n";
	else	cout << "Yes\n";
	return 0;
}

