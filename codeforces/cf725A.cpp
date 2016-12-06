#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, l=0, r=0;
	cin >> n;
	string s;
	cin >> s;
	for ( int i=0; i<n; i++ ) {
		if ( s[i] == '>' )
			break;
		l++;
	}
	for ( int i=n-1; i>=0; i-- ) {
		if ( s[i] == '<' )
			break;
		r++;
	}
	cout << l+r << '\n';
	return 0;
}

