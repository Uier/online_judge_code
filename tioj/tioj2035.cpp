#include <iostream>
#include <math.h>
#define int long long
using namespace std;
main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int b, n, m, lv = 0, sum = 0, dp[8] = {1,0,0,0,0,0,0,0};
	cin >> b >> n;
	m = n;
	for ( int i=1; i<8; ++i )	dp[i] = dp[i-1]*b;
	while ( m/=10 )	lv++;
	for ( int i=0, j=n; i<lv+1; ++i, j/=10, n/=10 )
		sum += (pow(j%10,lv+1)-(n%10)*dp[i]);
	if ( sum )	cout << "NO\n";
	else	cout << "YES\n";
	return 0;
}

