#include <iostream>
#define int long long
#define maxn 200005
using namespace std;
int arr[maxn], cost[maxn];
main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, h;
	cin >> n >> h;
	for ( int i=0, l, r, pr; i<n; ++i ) {
		cin >> l >> r;
		arr[i] = r-l;
		if ( i )	cost[i] = l-pr;
		pr = r;
	}
	int ptl = 0, ptr = 0, sum = 0, rem = h, val = 0;
	int ans = -1, bonus = h;
	while ( ptl <= ptr ) {
		while ( ptr < n && sum+cost[ptr] < h ) {
			val += arr[ptr]+cost[ptr];
			sum += cost[ptr++];
			rem = h-sum;
		}
		if ( ans == -1 || val+rem > ans )
			ans = val+rem;
		val -= arr[ptl++];
		val -= cost[ptl];
		sum -= cost[ptl];
	}
	if ( n == 1 )	cout << h+arr[0] << '\n';
	else	cout << ans << '\n';
	return 0;
}

