#include <iostream>
#include <algorithm>
#define maxn 5005
using namespace std;
struct paint {
	int l, r;
} arr[maxn];
int cnt[maxn], sc[maxn];
int main() {
	ios::sync_with_stdio(false);
	//   sync_with_YinHsuan(true);
	cin.tie(0);
	int n, q, ans = 0;
	cin >> n >> q;
	for ( int i=0; i<q; ++i ) {
		cin >> arr[i].l >> arr[i].r;
		for ( int j=arr[i].l; j<=arr[i].r; ++j )	cnt[j]++;
	}
	for ( int i=1; i<=n; ++i )	if ( cnt[i] )	ans++;
	int idx = -1, idx2 = -1;
	for ( int i=0; i<q; ++i ) {
		sc[i] = 0;
		for ( int j=arr[i].l; j<=arr[i].r; ++j )
			if ( cnt[j] == 1 )
				sc[i]++;
		if ( idx == -1 || sc[i] < sc[idx] || (sc[i] == sc[idx] && arr[idx].r-arr[idx].l > arr[i].r-arr[i].l) ) {
			idx = i;
		}
	}
//	cout << ans << '\n';
	ans -= sc[idx];
//	cout << ans << '\n';
	for ( int i=arr[idx].l; i<=arr[idx].r; ++i )	cnt[i]--;
	for ( int i=0; i<q; ++i ) {
		if ( i == idx )	continue;
		sc[i] = 0;
		for ( int j=arr[i].l; j<=arr[i].r; ++j )
			if ( cnt[j] == 1 )
				sc[i]++;
		if ( idx2 == -1 || sc[i] < sc[idx2] || (sc[i] == sc[idx2] && arr[idx2].r-arr[idx2].l > arr[i].r-arr[i].l) ) {
			idx2 = i;
		}
	}	
	cout << ans-sc[idx2] << '\n';
	return 0;
}

