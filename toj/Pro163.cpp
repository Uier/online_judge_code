#include <iostream>
using namespace std;
bool a[11];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	string s;
	while ( T-- ) {
		cin >> s;
		for ( int i=0; i<11; ++i )
			a[i] = (s[i]=='0' ? false : true);
		cout << (a[0]^a[1]^a[3]^a[4]^a[6]^a[8]^a[10]);
		cout << (a[0]^a[2]^a[3]^a[5]^a[6]^a[9]^a[10]);
		cout << a[0];
		cout << (a[1]^a[2]^a[3]^a[7]^a[8]^a[9]^a[10]);
		cout << a[1] << a[2] << a[3];
		cout << (a[4]^a[5]^a[6]^a[7]^a[8]^a[9]^a[10]);
		for ( int i=4; i<11; ++i )
			cout << a[i];
		cout << '\n';
	}
	return 0;
}

