#include <iostream>
using namespace std;
int a[105];
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int n, m, k, mn = 1000;
	cin >> n >> m >> k;
	for ( int i=1; i<=n; ++i )
		cin >> a[i];
	for ( int i=m-1; i>0; --i )
		if ( a[i] != 0 && a[i] <= k ) {
			mn = min(mn,m-i);
			break;
		} 
	for ( int i=m+1; i<=n; ++i )
		if ( a[i] != 0 && a[i] <= k ) {
			mn = min(mn,i-m);
			break;
		}
	cout << mn*10 << '\n';
	return 0;
}

