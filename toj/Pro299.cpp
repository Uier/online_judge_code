#include <iostream>
#include <algorithm>
#include <math.h>
//	20points 80-TLE
using namespace std;
typedef pair<int,int> L;
L a[5010];
long long ans;
bool operator < (L x, L y) {
	return x.first < y.first;
}
void check(int l, int r) {
	long long sum=0;
	for ( int i=l+1; i<r; i++ )
		sum += a[i].second;
	if ( sum==(a[l].second+1+a[r].second-1)*(r-l-1)/2 ) {
		ans++;
//		cout << "i: " << l << " j: " << r << " sum: " << sum << '\n';
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, n;
	cin >> t;
	while ( t-- ) {
		cin >> n;
		for ( int i=1; i<=n; i++ ) {
			cin >> a[i].first;
			a[i].second = i;
		}
		sort(a+1,a+n+1);
		ans = 0;
		for ( int i=2; i<=n; i++ )
			for ( int j=1; j<i; j++ )
				if ( a[i].first-a[j].first == abs(a[i].second-a[j].second) )
					check(j,i);
		cout << ans << '\n';
	}
	return 0;
}

