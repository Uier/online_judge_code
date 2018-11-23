#include <iostream>
#define int long long
using namespace std;
main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int k, d, t;
	cin >> k >> d >> t;
	if ( k%d == 0 )	return cout << t << '\n', 0;
	t *= 2;
	int cyc = k*2 + (d*(k/d+1) - k);
	int cnt = t/cyc, rem = t%cyc;
	double ans = d*(k/d+1)*cnt;
	if ( rem > 2*k )
		ans += rem-2*k+k;
	else
		ans += (double)rem/2;
	printf("%.10lf\n", ans);
	return 0;
}

