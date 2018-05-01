#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, cnt = 0;
	string s;
	cin >> n >> s;
	for ( int i=0; i<n; ++i ) {
		if ( s[i] == '1' )	cnt++;
	}
	if ( s != "0" )	cout << 1;
	for ( int i=0; i<n-cnt; ++i ) {
		cout << 0;
	}
	cout << '\n';
	return 0;
}