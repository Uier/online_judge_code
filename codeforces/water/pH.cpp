#include <iostream>
using namespace std;
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int n;
	cin >> n;
	for ( int i=0, cnt=0, sw = 0; i<n; ++i ) {
		if ( cnt < 2 ) {
			cout << 'a';
			cnt++;
		} else {
			cout << 'b';
			sw++;
		}
		if ( sw == 2 ) {
			sw = cnt = 0;
		}
	}
	cout << '\n';
	return 0;
}

