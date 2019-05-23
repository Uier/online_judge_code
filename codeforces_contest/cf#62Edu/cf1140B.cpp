#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	//   sync_with_YinHsuan(true);
	cin.tie(0);
	int t, n;
	cin >> t;
	string s;
	while ( t-- && cin >> n ) {
		cin >> s;
		if ( s[0] == '<' && s[n-1] == '>' ) {
			int cnt1 = 0, cnt2 = 0;
			for ( int i=0; i<n; ++i ) {
				if ( s[i] == '>' )	break;
				cnt1++;
			}
			for ( int i=n-1; i>=0; --i ) {
				if ( s[i] == '<' )	break;
				cnt2++;
			}
			cout << min(cnt1,cnt2) << '\n';
		} else {
			cout << 0 << '\n';
		}
	}
	return 0;
}

