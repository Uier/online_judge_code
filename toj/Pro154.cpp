#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
pii a[100005];
bool cmp(pii x, pii y) {
	if ( x.second == y.second )	return x.first < y.first;
	return x.second > y.second;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T, N, x;
	cin >> T;
	while ( T-- && cin >> N ) {
		for ( int i=0; i<N; ++i ) {
			cin >> a[i].second;
			a[i].first = i+1;
		}
		sort(a,a+N,cmp);
		cout << a[0].first;
		long long sum = a[0].second;
		for ( int i=1; i<N; ++i ) {
			cout << ' ' << a[i].first;
			sum += a[i].second*(i+1);
		}
		cout << '\n' << sum << '\n';
	}
	return 0;
}

