#include <iostream>
#define maxn 1000005
using namespace std;
int k, n, mul[5];
struct dot {
	int x, y;
} a[maxn];
bool check(int b) {
	int pass = 0;
	for ( int i=0; i<n; ++i ) {
		int tmp = 0, Nx = a[i].x;
		for ( int j=0; j<5; ++j ) {
			tmp += mul[4-j]*Nx;
			Nx *= a[i].x;
		}
		if ( tmp+b-a[i].y <= 0 )	pass++;
	}
	return (pass >= k);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> k;
	for ( int i=0; i<5; ++i )
		cin >> mul[i];
	cin >> n;
	for ( int i=0; i<n; ++i )
		cin >> a[i].x >> a[i].y;
	int l = -1e9, r = 1e9;
	while ( l <= r ) {
		int mid = (l+r)/2;
		if ( check(mid) )
			l = mid;
		else
			r = mid;
		if ( l+1 == r ) {
			if ( check(r) )
				l = r;
			break;
		}
	}
	cout << l << '\n';
	return 0;
}

