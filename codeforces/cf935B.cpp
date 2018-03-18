#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
//	cin.tie(0);
	int n;
	long long ans = 0;
	string s;
	cin >> n >> s;
	int x = 0, y = 0, flag = 0;
	for ( int i=0; i<s.size(); ++i ) {	// 1 > ;  2 ^
		if ( s[i] == 'U' ) {
			if ( flag == 2 )
				ans++;
			y++;
		}
		if ( s[i] == 'R' ) {
			if ( flag == 1 )
				ans++;
			x++;
		}
		flag = 0;
		if ( x == y && x != 0 ) {
			if ( s[i] == 'U' )	flag = 2;
			else	flag = 1;
		}
	}
	cout << ans << '\n';
	return 0;
}

