#include <iostream>
using namespace std;
typedef pair<int,int> pii;
//int arr[1005], pre[1005];
pii arr[1005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, q, l, r;
	cin >> n >> m >> q;
	string s, t;
	cin >> s >> t;
	int lens = s.size(), lent = t.size(), pt = 0;
	for ( int i=0; i<lens; ++i ) {
		bool flag = 1;
		for ( int j=0; j<lent; ++j )
			if ( s[i+j] != t[j] ) {
				flag = 0;
				break;
			}
		if ( flag )	arr[pt++] = pii{i+1,i+m};
	}
	for ( int i=0; i<q; ++i ) {
		cin >> l >> r;
		int ans = 0;
		for ( int j=0; j<pt; ++j ) {
			if ( l <= arr[j].first && r >= arr[j].second )
				ans++;
		}
		cout << ans << '\n';
	}
	return 0;
}

