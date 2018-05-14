#include <iostream>
#include <algorithm>
#define maxn 200005
using namespace std;
typedef pair<int,int> pii;
int a[maxn], c[maxn];
pii b[maxn];
bool cmp(pii u, pii v) {
	return u.first < v.first;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k, x, y;
	cin >> n >> k;
	for ( int i=1; i<=n; ++i ) {
		cin >> a[i];
		b[i-1] = pii{a[i],i};
	}
	sort(b,b+n,cmp);
	for ( int i=0; i<n; ++i ) {
		pii tmp = b[i];
		int pos = lower_bound(b,b+n,tmp,cmp)-b;
		c[tmp.second] = pos;
	}
	for ( int i=0; i<k; ++i ) {
		cin >> x >> y;
		if ( a[x] > a[y] )	c[x]--;
		else if ( a[y] > a[x] )	c[y]--;
	}
	for ( int i=1; i<=n; ++i )
		cout << c[i] << ' ';
	cout << '\n';
	return 0;
}

