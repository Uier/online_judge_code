#include <iostream>
#include <algorithm>
#define maxn 300005
using namespace std;
struct pii {
	int x, y, z;
} a[maxn];
bool cmp(pii u, pii v) {
	if ( u.x == v.x )	return u.y > v.y;
	return u.x < v.x;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for ( int i=0; i<n; ++i ) {
		cin >> a[i].x >> a[i].y;
		a[i].z = i+1;
	}
	sort(a,a+n,cmp);
	int R = a[0].y, index = a[0].z;
	bool flag = false;
	for ( int i=1; i<n; ++i ) {
		if ( a[i].y <= R ) {
			flag = true;
			cout << a[i].z << ' ' << index << '\n';
			break;
		}
		if ( a[i].y > R ) {
			R = a[i].y;
			index = a[i].z;
		}
	}
	if ( !flag )	cout << -1 << ' ' << -1 << '\n';
	return 0;
}