#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int x, p[1005], dp[1005];
struct E {
	int a, b, c;
	bool operator < (const E &t )const {
		return a < t.a;
	}
} d[1005];
void trace(int i) {
	if ( i == -1 ) return;
	trace(p[i]);
	cout << d[i].c << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	x = 0;
	while ( cin >> d[x].a >> d[x].b )
		d[x].c = x+1, x++;
	sort(d,d+x); 
	memset(p,-1,sizeof p);
	int n=0, pt=0;
	for ( int i=0; i<x; i++ ) {
		dp[i] = 1;
		for ( int j=0; j<i; j++ )
			if ( d[i].a > d[j].a && d[j].b > d[i].b && dp[j]+1 > dp[i] ) {
				dp[i] = dp[j] + 1;
				p[i] = j;
			}
		if ( dp[i] > n ) {
			n = dp[i];
			pt = i;
		}
	}
	cout << n << '\n';
	trace(pt);
	return 0;
}

