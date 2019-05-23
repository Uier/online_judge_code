#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t, n, cs = 1;
	string s;
	cin >> t;
	while ( t-- && cin >> n >> s ) {
		string t = "";
		int sz = 2*n-2;
		for ( int i=0; i<sz; ++i ) {
			if ( s[i] == 'E' )	t += "S";
			else	t += "E";
		}
		cout << "Case #" << cs++ << ": " << t << '\n';
	}
	return 0;
}

