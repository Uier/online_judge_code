#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
pii a[1000005];
bool cmp(pii u, pii v) {
	return (u.first==v.first ? u.second<v.second : u.first<v.first);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, q, x, y;
	cin >> n >> m >> q;
	for ( int i=0; i<m; ++i ) {
		cin >> a[i].first >> a[i].second;
		if ( a[i].first > a[i].second )	swap(a[i].first,a[i].second);
	}
	sort(a,a+m,cmp);
	while ( q-- && cin >> x >> y ) {
		if ( x > y )	swap(x,y);
		int pos = upper_bound(a,a+m,pii{x,y},cmp)-a;
		if ( pos == 0 || a[pos-1] != pii{x,y} )
			cout << "no\n";
		else	cout << "yes\n";
	}
	return 0;
}
