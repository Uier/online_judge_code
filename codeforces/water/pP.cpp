#include <iostream>
using namespace std;
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int n;
	string s, a = "", b = "";
	cin >> n >> s;
	for ( int i=n-1, j=1; i>=0; --i, j^=1 ) {
		if ( j ) {
			b += s[i];
		} else
			a += s[i];
	}
	cout << a;
	int lb = b.size();
	for ( int i=lb-1; i>=0; --i )	cout << b[i];
	cout << '\n';
	return 0;
}

