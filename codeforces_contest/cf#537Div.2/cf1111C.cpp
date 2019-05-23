#include <iostream>
#include <algorithm>
#define int long long
#define maxk 100005
using namespace std;
int dp[31], arr[maxk], n, k, A, B;
int solve(int l, int r) {
	if ( l == r ) {
		int na = upper_bound(arr,arr+k,l)-lower_bound(arr,arr+k,l);
		if ( na == 0 )	return A;
		else	return na*B;
	}
	int mid = l+r>>1;
	int na = upper_bound(arr,arr+k,r)-lower_bound(arr,arr+k,l);
	if ( na == 0 )	return A;
	return min(solve(l,mid)+solve(mid+1,r),na*B*(r-l+1));
}
main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	dp[0] = 1;
	for ( int i=1; i<31; ++i )	dp[i] = dp[i-1]<<1;
	cin >> n >> k >> A >> B;
	for ( int i=0; i<k; ++i )	cin >> arr[i];
	sort(arr,arr+k);
	cout << solve(1,dp[n]) << '\n';
	return 0;
}

