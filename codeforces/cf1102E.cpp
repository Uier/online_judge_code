#include <iostream>
#include <map>
#define maxn 200005
using namespace std;
int arr[maxn];
map<int,int> M, cnt;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m = 0, tmp = 0;
	cin >> n;
	for ( int i=0; i<n; ++i ) {
		cin >> arr[i];
		M[arr[i]] = i;
		cnt[arr[i]]++;
	}
	// WAAAA
//	for ( int i=0; i<n; ) {
//		cout << "i,M,cnt: " << i << ' ' << M[arr[i]] << ' ' << cnt[arr[i]] << '\n';
//		if ( M[arr[i]] != i ) {
//			m++;
//			i = M[arr[i]]+1;
//		} else {
//			if ( cnt[arr[i]] == 1 )	m++;
//			i++;
//		}
//	}
	cout << "m: " << m << '\n';
	m--;
	long long ans = 1, base = 2, mod = 998244353;
	while ( m ) {
		if ( m&1 )	ans *= base;
		ans %= mod;
		base *= base;
		base %= mod;
		m >>= 1;
	}
	cout << ans << '\n';
	return 0;
}

