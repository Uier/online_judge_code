#include <iostream>
using namespace std;
int failure[200005];
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	string s, t;
	while ( cin >> s ) {
		cout << "hello\n";
		int l = s.size(), ans = 0;
		t.clear();
		for ( int i=0; i<l; i++ )
			t.push_back(s[l-1-i]);
		int j = failure[0] = -1;
		for ( int i=1; i<l; i++ ) {
			while ( j != -1 && t[i] != t[j+1] )	j = failure[j];
			if ( t[i] == t[j+1] )	j++;
			failure[i] = j;
		}
		for ( int i=0; i<l; i++ )
			ans = max(ans,failure[i]+1);
		cout << ans << '\n';
	}
	return 0;
}

