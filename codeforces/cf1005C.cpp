#include <iostream>
#include <algorithm>
#include <map>
#define maxn 120005
using namespace std;
int a[maxn], dp[31];
bool v[maxn];
map<int,int> M;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	dp[0] = 1;
	for ( int i=1; i<31; ++i )	dp[i] = dp[i-1]<<1;
	int n;
	cin >> n;
	for ( int i=0; i<n; ++i ) {
		cin >> a[i];
		M[a[i]]++;
	}
	sort(a,a+n);
	for ( int i=0; i<n; ++i ) {
		if ( v[i] ) continue;
		for ( int j=0; j<31; ++j )
			if ( dp[j] > a[i] ) {
				int tar = dp[j]-a[i];
				int pos = lower_bound(a,a+n,tar)-a;
				if ( pos < n && a[pos] == tar && (pos != i || M[tar] > 1) ) {
					v[i] = true;
					break;
				}
			}
	}
	int ans = 0;
	for ( int i=0; i<n; ++i )
		if ( !v[i] )	ans++;
	cout << ans << '\n';
	return 0;
}

