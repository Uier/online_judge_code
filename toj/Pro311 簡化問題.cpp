#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
pii a[15005];
bool cmp(pii x, pii y) {
	return x.second < y.second;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, q, l, r;
	cin >> n >> q;
	for ( int i=0; i<n; ++i ) {
		a[i].first = i+1;
		cin >> a[i].second;
	}
	sort(a,a+n,cmp);
	while ( q-- ) {
		cin >> l >> r;
		int sum = 0, num = 0, x = -1;
		for ( int i=0; i<n; ++i ) {
			if ( l <= a[i].first && a[i].first <= r ) {
				if ( a[i].second != x )	num++;
				x = a[i].second;
				sum += num;
			}
		}
		cout << sum << '\n';
	}
	return 0;
}

