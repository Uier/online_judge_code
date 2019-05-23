#include <iostream>
#include <vector>
#include <algorithm>
#define maxn 200005
#define int long long
using namespace std;
typedef pair<int,int> pii;
int arr[maxn];
pii brr[maxn];
bool bb[maxn];
main() {
	ios::sync_with_stdio(false);
	//   sync_with_YinHsuan(true);
	cin.tie(0);
	int n, m, k;
	long long ans = 0;
	cin >> n >> m >> k;
	for ( int i=0; i<n; ++i ) {
		cin >> arr[i];
		brr[i] = pii{arr[i],i};
	}
	sort(brr,brr+n);
	reverse(brr,brr+n);
	for ( int i=0; i<m*k; ++i ) {
		bb[brr[i].second] = true;
		ans += brr[i].first;
	}
	cout << ans << '\n';
	int cntcnt = 0;
	for ( int i=0; i<n; ++i ) {
		int cnt = 0, r = i;
		while ( cnt < m ) {
			if ( bb[r] )	cnt++;
			r++;
		}
		cout << r << ' ';
		cntcnt++;
		i = r-1;
		if ( cntcnt == k-1 )	break;
	}
	cout << '\n';
	return 0;
}

