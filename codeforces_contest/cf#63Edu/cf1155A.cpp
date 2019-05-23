#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#include <map>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, cnt[26];
	string s;
	cin >> n >> s;
	for ( int i=0; i<26; ++i )	cnt[i] = -1;
	for ( int i=0; i<n; ++i ) {
		if ( cnt[s[i]-'a'] == -1 )	cnt[s[i]-'a'] = i;
		for ( int j=s[i]-'a'+1; j<26; ++j ) {
			if ( cnt[j] != -1 ) {
				cout << "YES\n";
				cout << cnt[j]+1 << ' ' << i+1 << '\n';
				return 0;
			}
		}
	} 
	cout << "NO\n";
	return 0;
}

