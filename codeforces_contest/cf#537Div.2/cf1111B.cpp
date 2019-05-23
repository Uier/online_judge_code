#include <iostream>
#include <algorithm>
#define maxn 100005
#define int long long
using namespace std;
int arr[maxn];
main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k, m;
	cin >> n >> k >> m;
	for ( int i=0; i<n; ++i )	cin >> arr[i];
	sort(arr,arr+n);
	int pt = n-2;
	while ( pt >= 0 && arr[pt] == arr[n-1] )	pt--;
	int rem = n-1-pt;
	if ( n-rem > m ) {
		double sum = 0;
		for ( int i=m; i<n; ++i )	sum += arr[i];
		printf("%.10lf\n", sum/(double)(n-m));
	} else {
		m -= (n-rem);
		double sum = (double)rem*(double)arr[n-1];
		int mx = min(rem*k,m);
		printf("%.10lf\n", (double)(sum+mx)/(double)rem);
	}
	return 0;
}

