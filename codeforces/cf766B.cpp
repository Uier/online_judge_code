#include <iostream>
#include <algorithm>
using namespace std;
int a[100005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for ( int i=0; i<n; i++ )
		cin >> a[i];
	sort(a,a+n);
	bool flag = false;
	for ( int i=1; i<n; i++ ) {
		int x = a[i-1], y = a[i];
		int z = *lower_bound(a+1+i,a+n,y);
		if ( z < x+y && z > 0 ) {
			flag = true;
			break;
		}
	}
	if ( flag ) cout << "YES\n";
	else    cout << "NO\n";
	return 0;
}

