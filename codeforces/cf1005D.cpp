#include <iostream>
using namespace std;
int a[200005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	int len = s.size(), ans = 0;
	for ( int i=0; i<len; ++i ) {
		a[i] = (int)(s[i]-'0')%3;
		if ( a[i] == 0 )
			ans++;
	}
	for ( int i=0; i<len; ++i ) {
		while ( i < len && a[i] == 0 )	i++;
		if ( a[i] == 1 && (i+1 < len && a[i+1] == 2) ) {
			ans++;
			i = i+1;
		} else if ( a[i] == 1 && (i+2 < len && a[i+1] == 1 && a[i+2] == 1) ) {
			ans++;
			i = i+2;
		} else if ( a[i] == 2 && (i+1 < len && a[i+1] == 1 ) ) {
			ans++;
			i = i+1;
		} else if ( a[i] == 2 && (i+2 < len && a[i+1] == 2 && a[i+2] == 2) ) {
			ans++;
			i = i+2;
		}
	}
	cout << ans << '\n';
	return 0;
}

