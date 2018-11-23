#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, cnt = 0, dis = 0, ans = 0;
	string s;
	cin >> n >> s;
	for ( int i=0; i<n; ++i ) {
		if ( s[i] == '8' )	cnt++;
	}
	for ( int i=0; i<=cnt; ++i ) {
		dis = n-i;
		ans = max(ans,min(i,dis/10));
	}
	cout << ans << '\n';
	return 0;
}

