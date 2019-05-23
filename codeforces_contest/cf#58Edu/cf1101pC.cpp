#include <iostream>
#include <algorithm>
#define maxn 100005
using namespace std;
struct seg {
	int l, r, id, gp;
} arr[maxn];
inline bool cmp(seg x, seg y) {
	if ( x.l == y.l )	return x.r < y.r;
	return x.l < y.l;
}
inline bool idx(seg x, seg y) {
	return x.id < y.id;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t, n;
	cin >> t;
	while ( t-- && cin >> n ) {
		for ( int i=0; i<n; ++i ) {
			cin >> arr[i].l >> arr[i].r;
			arr[i].id = i;
			arr[i].gp = 0;
		}
		sort(arr,arr+n,cmp);
		int rem = arr[0].r, remgp = 1;
		arr[0].gp = 1;
		for ( int i=1; i<n; ++i ) {
			if ( arr[i].l <= rem )
				arr[i].gp = remgp;
			else
				arr[i].gp = (remgp == 1 ? 2 : 1);
			if ( arr[i].r > rem ) {
				rem = arr[i].r;
				remgp = arr[i].gp;
			}
		}
		bool one = false, two = false;
		for ( int i=0; i<n; ++i )
			if ( arr[i].gp == 1 )	one = 1;
			else	two = 1;
		if ( !one || !two )	cout << -1 << '\n';
		else {
			sort(arr,arr+n,idx);
			for ( int i=0; i<n; ++i )	cout << arr[i].gp << ' ';
			cout << '\n';
		}
	}
	return 0;
}

