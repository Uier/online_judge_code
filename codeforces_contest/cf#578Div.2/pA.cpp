#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	string s;
	cin >> n >> s;
	int len = s.size();
	string ans = "0000000000";
	for ( int i=0; i<len; ++i ) {
		if ( s[i] == 'L' ) {
			for ( int j=0; j<10; ++j ) {
				if ( ans[j] == '0' ) {
					ans[j] = '1';
					break;
				}
			}
		} else if ( s[i] == 'R' ) {
			for ( int j=9; j>=0; --j ) {
				if ( ans[j] == '0' ) {
					ans[j] = '1';
					break;
				}
			}
		} else {
			ans[s[i]-'0'] = '0';
		}
	}
	cout << ans << '\n';
	return 0;
}