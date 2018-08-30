#include <iostream>
using namespace std;
int a[10];
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int k;
	string s;
	cin >> k >> s;
	int len = s.size(), sum =0;
	for ( int i=0; i<len; ++i ) {
		sum += (s[i]-'0');
		a[s[i]-'0']++;
	}
	if ( sum >= k ) {
		cout << 0 << '\n';
	} else {
		int pt = 0, ans = 0;
		k -= sum;
		while ( k > 0 ) {
			while ( pt < 10 && a[pt] == 0 )	pt++;
			k -= (9-pt);
			a[pt]--;
			ans++;
		}
		cout << ans << '\n';
	}
	return 0;
}

