#include <iostream>
using namespace std;
int z[200005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s, t;
	while ( cin >> s ) {
		int l = s.size(), ans = 0, L = 0, R = 0;
		t.clear();
		for ( int i=0; i<l; i++ )
			t.push_back(s[l-1-i]);
		z[0] = l;
		for ( int i=1; i<l; i++ ) {
			int ii = i-L, n = R+1-i;
			if ( i > R || z[ii] >= n ) {
				int j = ((i>R) ? i : (R+1));
				while ( j < l && t[j] == t[j-i] )	j++;
				z[i] = j-i;
				L = i;
				R = j-1;
			}
			else
				z[i] = z[ii];
			if ( z[i] >= i )
				ans = i;
		}
		cout << ans << '\n';
	}
	return 0;
}

