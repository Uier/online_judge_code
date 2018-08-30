#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	int len;
	cin >> len;
	cin >> s;
	int one = 0, zero = 0;
	for ( int i=0; i<len; ++i ) {
		if ( s[i] == '0' ) {
			if ( one == 0 )
				zero++;
			else one--;
		}
		else if ( s[i] == '1' ) {
			if ( zero == 0 )
				one++;
			else zero--;
		}
	}
	cout << one+zero << '\n';
	return 0;
}

