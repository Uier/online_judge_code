#include <iostream>
#define int long long
#define maxp 1000001
#define logn 32
using namespace std;
//int dp[logn];
bool npr[maxp];
main() {
	ios::sync_with_stdio(false);
	//   sync_with_YinHsuan(true);
	cin.tie(0);
	npr[0] = npr[1] = 1;
	for ( int i=2; i<maxp; ++i )
		if ( !npr[i] )
			for ( int j=i*i; j<maxp; j+=i )
				npr[j] = 1;
	int n, b, ans = 0;
	cin >> n >> b;
	for ( int i=1; i*i<=b; ++i ) {
		if ( b%i || npr[b/i] )	continue;
		int m = n, k = b/i, tmp = 0, tmp2 = 0, _p = b/i;
		while ( m ) {
			tmp += m/k;
			m /= k;
		}
		while ( _p <= b ) {
			_p *= k;
			tmp2++;
		} 
		ans += tmp/tmp2;
//		if ( i == b/i ) {
//			int tmp = 0, tmp2 = 0;
//			while ( m >= b/i ) {
//				tmp += m/(b/i);
//				m /= b/i;
//			}
//			m = n;
//			while ( m >= b ) {
//				tmp2 += m/b;
//				m /= b;
//			}
//			tmp -= tmp2*2;
//			ans += tmp/2;
////			while ( m >= b/i ) {
////				ans += (m/(b/i))/2;
//////				ans++;
////				m /= b/i;
////			}
//////			ans--;
//			continue;
//		}
//		while ( m >= b/i ) {
//			ans += m/(b/i);
//			m /= b/i;
//		}
	}
	cout << ans << '\n';
	return 0;
}

