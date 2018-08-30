#include <iostream>
using namespace std;
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	string s, t;
	cin >> s >> t;
	int ls = s.size(), lt = t.size();
	cout << s[0];
	for ( int i=1; i<ls; ++i ) {
		if ( s[i] < t[0] )
			cout << s[i];
		else	break;
	}
	cout << t[0];
	cout << '\n';
	return 0;
}
