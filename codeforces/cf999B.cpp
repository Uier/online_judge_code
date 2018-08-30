#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	string s;
	cin >> n;
	cin >> s;
	int m = 1;
	while ( m <= n ) {
		string t = "";
		for ( int i=0; i<m; ++i ) {
			t += s[i];
		}
		int len = t.size();
		for ( int i=0; i<len/2; ++i )
			swap(t[i],t[len-1-i]);
		for ( int i=0; i<len; ++i )
			s[i] = t[i];
		m++;
		if ( m > n )	break;
		while ( n%m ) m++;
	}
	cout << s << '\n';
	return 0;
}

