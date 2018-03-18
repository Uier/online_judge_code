#include <iostream>
using namespace std;
bool del[105];
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int n;
	string s;
	cin >> n >> s;
	bool hi = false;
	for ( int i=0; i<n; ++i ) {
		if ( s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o'
			|| s[i] == 'u' || s[i] == 'y' ) {
			if ( hi )	del[i] = true;	
			else	hi = true;
		} else
			hi = false;
	}
	for ( int i=0; i<n; ++i )
		if ( !del[i] )
			cout << s[i];
	cout << '\n';
	return 0;
}

