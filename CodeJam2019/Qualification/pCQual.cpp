#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> used;
int arr[105];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t, n, l, x, y, cs = 1;
	cin >> t;
	while ( t-- && cin >> n >> l >> x >> y ) {
		used.clear();
		int gcd = __gcd(x,y);
		arr[0] = x/gcd;
		arr[1] = gcd;
		arr[2] = y/gcd;
		for ( int i=2; i<l; ++i ) {
			cin >> x;
			arr[i+1] = x/arr[i];
		}
		for ( int i=0; i<=l; ++i )	used.emplace_back(arr[i]);
		sort(used.begin(),used.end());
		used.resize(unique(used.begin(),used.end())-used.begin());
		cout << "Case #" << cs++ << ": ";
		for ( int i=0; i<=l; ++i ) {
			int pos = lower_bound(used.begin(),used.end(),arr[i])-used.begin();
			cout << char('A'+pos);
		}
		cout << '\n';
	}
	return 0;
}

