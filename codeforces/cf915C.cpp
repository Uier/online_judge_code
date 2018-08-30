#include <iostream>
#include <algorithm>
using namespace std;
string s, t, ans;
int V[20], lens, lent;
bool valid(int ignore) {
	string tmp = "", cmp = ans;
	for ( int i=lens-1; i>=0; --i ) {
		if ( V[i] || i == ignore )	continue;
		tmp += s[i];
	}
	cmp += s[ignore];
	cmp += tmp;
	return cmp <= t;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s >> t;
	lens = s.size(); lent = t.size();
	sort(s.begin(),s.end());
	reverse(s.begin(),s.end());
	if ( lens == lent ) {
		bool flag = false;
		for ( int i=0; i<lens; ++i ) {
			for ( int j=0; j<lens; ++j ) {
				if ( V[j] )	continue;
				if ( s[j] == t[i] && valid(j) ) {
					ans += s[j];
					V[j] = true;
					break;
				} else if ( s[j] < t[i] ) {
					ans += s[j];
					V[j] = true;
					flag = true;
					break;
				}
			}
			if ( flag )	break;
		}
		if ( ans.size() != lent )
			for ( int i=0; i<lens; ++i )
				if ( !V[i] )
					ans += s[i];
		cout << ans << '\n';
	} else	cout << s << '\n';
	return 0;
}
