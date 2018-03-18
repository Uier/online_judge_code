#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
bool cmp(pii x, pii y) {
	if ( x.first == y.first )
		return x.second > y.second;
	return x.first < y.first;
}
pii a[10005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, sum, R;
	while ( cin >> n ) {
		for ( int i=0; i<n; ++i )
			cin >> a[i].first >> a[i].second;
		sort(a,a+n,cmp);
		sum = a[0].second-a[0].first;
		R = a[0].second;
		for ( int i=1; i<n; ++i )
			if ( a[i].first != a[i-1].first && a[i].second > R ) {
				sum += (a[i].second-a[i].first) - (R-a[i].first)*((R-a[i].first)>0);
				L = a[i].second;
			}
		cout << sum << '\n';
	}
	return 0;
}

