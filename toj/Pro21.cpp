#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
pii a[1000005];
bool cmp(pii x, pii y) { // sorting by left bound
	if ( x.first == y.first )	return x.second > y.second;
	return x.first < y.first;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T, N;
	cin >> T;
	while ( T-- && cin >> N ) {
		for ( int i=0; i<N; ++i )
			cin >> a[i].first >> a[i].second;
		sort(a,a+N,cmp);
		int R = 0, ans = 0;
		for ( int i=0; i<N; ++i ) {
			ans += (a[i].first-R>0 ? a[i].first-R : R-a[i].first);
			R += a[i].second;
		}
		cout << ans << '\n';
	}
	return 0;
}

