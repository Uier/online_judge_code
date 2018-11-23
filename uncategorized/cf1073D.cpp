#include <iostream>
#include <algorithm>
#define maxn 200005
#define int long long
using namespace std;
int arr[maxn];
main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, t, mn = 1e9;
	cin >> n >> t;
	for ( int i=1; i<=n; ++i ) {
		cin >> arr[i];
		mn = min(mn,arr[i]);
	}
	int ans = 0, sum = 0;
	while ( t >= mn ) {
		int tmp = t, sum = 0, cnt = 0;
		for ( int i=1; i<=n; ++i )
			if ( tmp >= arr[i] ) {
				tmp -= arr[i];
				sum += arr[i];
				cnt += 1;
			}
		ans += (t/sum)*cnt;
		t %= sum;
	}
	cout << ans << '\n';
	return 0;
}

