#include <iostream>
using namespace std;
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int x;
	string a, b;
	cin >> x >> a >> b;
	if ( a[1] == '7' || b[1] == '7' )
		cout << 0 << '\n';
	else {
		int h = (a[0]-'0')*10+(a[1]-'0');
		int c = (b[0]-'0')*10+(b[1]-'0'), ans = 0;
		while ( c%10 != 7 && h%10 != 7 ) {
			ans++;
			c -= x;
			if ( c < 0 )	h--;
			h = (h+24)%24;
			c = (c+60)%60;
		}
		cout << ans << '\n';
	}
	return 0;
}

