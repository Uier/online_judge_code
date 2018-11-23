#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	string s;
	cin >> n >> s;
	int x = n-1;
	for ( int i=0; i<n-1; ++i ) {
		if ( s[i] > s[i+1] ) {
			x = i;
			break;
		}
	}
	for ( int i=0; i<n; ++i ) {
		if ( x == i )	continue;
		cout << s[i];
	}
	cout << '\n';
	return 0;
}

