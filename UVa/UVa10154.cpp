#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int dp[5610][5610];
struct turtle {
	int wei, cap;
} a[5610];
bool operator < (turtle x, turtle y) {
	if ( x.cap == y.cap )	return x.wei < y.wei;
	return x.cap < y.cap;
}
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int n = 1;
	while ( cin >> a[n].wei >> a[n].cap ) {
		a[n].cap -= a[n].wei;
		n++;
	}
	sort(a+1,a+n);
//	cout << "turtles\n";
//	for ( int i=1; i<n; i++ )	
//		cout << a[i].wei << ' ' << a[i].cap << '\n';
	memset(dp,0, sizeof dp);
	for ( int i=0; i<n; i++ ) {
		for ( int j=1; j<n; j++ )
			dp[i][j] = 2e9;
	for ( int i=1; i<n; i++ ) {
		for ( int j=1; j<n; j++ ) {
			dp[i][j]
		}
	}
	return 0;
}

