#include <iostream>
#include <algorithm>
#include <math.h>
#define maxn 100005
using namespace std;
int a[maxn*2];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n, w;
	cin >> n >> w;
	for ( int i=0; i<n*2; ++i )	cin >> a[i];
	sort(a,a+n+n);
	double g = a[0], b = a[n];
	if ( g*2 > b )	g = b/2;
	else	b = g*2;
	if ( w >= g*3*n )	printf("%.10lf\n", g*3*n);
	else	cout << w << '\n';
	return 0;
}

