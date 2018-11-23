#include <iostream>
#define int long long
using namespace std;
inline double val(double x) {
	x *= 0.000000001;
	return x;
}
main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int t, n;
	cin >> t;
	while ( t-- && cin >> n ) {
		if ( n == 0 ) {
			printf("Y 0 0\n");
			continue;
		} else if ( n == 1 || n == 2 ) {
			printf("N\n");
			continue;
		}
		int l = 1e9, r = n*5e8, m = n*1e9;
		while ( l < r ) {
			int mid = l+r>>1;
			double a = val(mid), b = val(m-mid);
			if ( a*b - n < 1e-6 && n - a*b < 1e-6 ) {
				printf("Y %.9lf %.9lf\n", a, b);
				break;
			}
			else if ( a*b > n )	r = mid;
			else l = mid;
			if ( l+1 == r ) {
				int mid = l+r>>1;
				double c = val(mid), d = val(m-mid);
				if ( c*d - n < 1e-6 && n - c*d < 1e-6 ) {
					printf("Y %.9lf %.9lf\n", c, d);
					break;
				} else {
					printf("N\n");
					break;
				}
			}
		}
	}
	return 0;
}

