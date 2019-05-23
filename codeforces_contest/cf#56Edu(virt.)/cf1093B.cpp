#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t, cnt[126];
	string s;
	cin >> t;
	while ( t-- && cin >> s ) {
		for ( int i=0; i<26; ++i )	cnt[i] = 0;
		int len = s.size(), diff = 0;
		bool p = true;
		for ( int i=0; i<len; ++i ) {
			if ( cnt[s[i]-'a'] == 0 )	diff++;
			cnt[s[i]-'a']++;
			if ( s[i] != s[len-1-i] )	p = false;
		} 
		if ( !p )	cout << s << '\n';
		else {
			if ( diff == 1 )	cout << -1 << '\n';
			else {
				sort(s.begin(),s.end());
				cout << s << '\n';
			}
		}
	}
	return 0;
}

