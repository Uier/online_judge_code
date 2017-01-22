#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, a, b, ans=999999;
	string s;
	cin >> n >> a >> b >> s;
	if ( n == 1 )
		cout << 0 << '\n';
	else if ( s[a-1] != s[b-1] ) {
		int c = a;
		for ( int i=c; i<n; i++ ) {
			if ( s[i] != s[c-1] ) {
				ans = i-c+1;
				break;
			}
			else
				c++;
		}
		c = a;
		for ( int i=c-2; i>=0; i-- ) {
			if ( s[i] != s[c-1] ) {
				ans = min(ans,c-1-i);
				break;
			}
			else
				c--;
		}
		cout << ans << '\n';
	}
	else
		cout << 0 << '\n';
	return 0;
}

