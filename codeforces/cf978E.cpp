#include <iostream>
#include <algorithm>
#define maxn 1005
using namespace std;
int a[1005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, w;
	cin >> n >> w >> a[0];
	for ( int i=1; i<n; ++i ) {
		cin >> a[i];
		a[i] += a[i-1];
	}
	sort(a,a+n);
	int neg = 0, pos = 0;
	if ( a[0] < 0 )	neg = a[0]*-1;
	if ( a[n-1] > 0 )	pos = a[n-1];
	if ( neg > w || pos > w )	cout << 0 << '\n';
	else {
		int mx = w-pos; // max of init
		int mn = neg; // min of init
		if ( mx-mn+1 < 0 )	cout << 0 << '\n';
		else	cout << mx-mn+1 << '\n';
	}
	return 0;
}

