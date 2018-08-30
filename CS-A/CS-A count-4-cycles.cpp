#include <iostream>
#include <algorithm>
#define maxn 100005
using namespace std;
pair<int,int> a[maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, ans = 0;
	cin >> n;
	for ( int i=0; i<n-1; ++i ) {
		cin >> a[i].first >> a[i].second;
		if ( a[i].first > a[i].second )	swap(a[i].first,a[i].second);
	}
	sort(a,a+n-1);
	for ( int i=0, x, y; i<n-1; ++i ) {
		cin >> x >> y;
		if ( x > y )	swap(x,y);
		int pos = lower_bound(a,a+n-1,make_pair(x,y))-a;
		if ( pos < n-1 && a[pos] == make_pair(x,y) )	ans++;
	}
	cout << ans << '\n';
	return 0;
}

