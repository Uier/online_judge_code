#include <iostream>
using namespace std;
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int n, x=0;
	string s, a="";
	cin >> n >> s;
	for ( int i=0; i<n; i++ ) {
		if ( s[i] == 'o' ) {
			int j=0;
			while ( i+j+2 < n && s[i+j+1] == 'g' && s[i+j+2] == 'o' )
				j += 2;
			if ( j )	a += "***";
			else	a.push_back(s[i]);
			i += j;
		}
		else	a.push_back(s[i]);
	}
	cout << a << '\n';
	return 0;
}

