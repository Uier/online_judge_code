#include <iostream>
using namespace std;
double a[5005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	for ( int i=0; i<n; ++i )
		cin >> a[i];
	double ans = 0;
	for ( int i=k; i<=n; ++i ) {
		double sum = 0, mx = 0;
		for ( int j=0; j<i; ++j )	mx += a[j];
		sum = mx;
		for ( int j=i; j<n; ++j ) {
			sum = sum-a[j-i]+a[j];
			mx = max(mx,sum);
		}
		ans = max(ans,mx/i);
	}
	printf("%.15lf\n", ans);
	return 0;
}

