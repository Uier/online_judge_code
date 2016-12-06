#include <iostream>
using namespace std;
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int n, h=0, m=0;
	string s;
	cin >> n >> s;
	h = (s[0]-'0')*10+(s[1]-'0');
	m = (s[3]-'0')*10+(s[4]-'0');
	if ( n == 12 ) {
		if ( m >= 60 )
			m %= 10;
		if ( h > 12 ) {
			if ( h%10 != 0 )
				h %= 10;
			else
				h = 10;
		}
		else if ( h == 0 )
			h = 1;
	}
	else {
		if ( m >= 60 )
			m %= 10;
		if ( h > 23 ) {
			if ( h %10 != 0 )
				h %= 10;
			else
				h = 0;
		}
	}
	if ( h < 10 )
		cout << 0;
	cout << h << ':';
	if ( m < 10 )
		cout << 0;
	cout << m << '\n';
	return 0;
}

