#include <iostream>
using namespace std;
int ans, n;
void bt(string s, int x) {
	ans = min(ans,x);
	for ( int i=0; i<12; i++ )
		if ( s[i] == 'o' ) {
			if ( i>=2 && s[i-1]=='o' && s[i-2]=='-' ) {
				s[i] = s[i-1] = '-';
				s[i-2] = 'o';
				bt(s,x-1);
				s[i] = s[i-1] = 'o';
				s[i-2] = '-';
			}
			if ( i<=9 && s[i+1]=='o' && s[i+2]=='-' ) {
				s[i] = s[i+1] = '-';
				s[i+2] = 'o';
				bt(s,x-1);
				s[i] = s[i+1] = 'o';
				s[i+2] = '-';
			}
		}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> n;
	while ( n-- && cin >> s ) {
		ans = 0;
		for ( int i=0; i<12; i++ )
			if ( s[i] == 'o' )
				ans++;
		bt(s,ans);
		cout << ans << '\n';
	}
	return 0;
}

