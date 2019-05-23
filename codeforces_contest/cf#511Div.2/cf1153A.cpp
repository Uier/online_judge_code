#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, t, s, d;
	cin >> n >> t;
	int mn = 1e9, idx = 0;
	for ( int i=0; i<n; ++i ) {
		cin >> s >> d;
		if ( s > t ) {
			if ( s < mn ) {
				mn = s;
				idx = i+1;
			}
		} else if ( s == t ) {
			idx = i+1;
			break;
		} else {
			while ( s < t ) {
				s += d;
			}
			if ( s < mn ) {
				mn = s;
				idx = i+1;
			}
		}
	}
	cout << idx << '\n';
	return 0;
}

