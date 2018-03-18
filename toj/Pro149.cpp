#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
pii a[100005];
bool cmp(pii x, pii y) {
	return x.first < y.first;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n, m;
	cin >> n >> m;
	for ( int i=0; i<n; ++i )
		cin >> a[i].first >> a[i].second;
	sort(a,a+n,cmp);
	for ( int i=0; i<n; ++i ) {
		if ( m < a[i].first )
			break;
		m += (a[i].second-a[i].first);
	}
	cout << m << '\n';
	return 0;
}

