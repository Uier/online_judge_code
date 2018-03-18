#include <iostream>
using namespace std;
int a[1000005];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
	int n;
	cin >> n;
	for ( int i=0; i<n; ++i )
		cin >> a[i];
	int len = a[n-1], sum = n;
	for ( int i=n-2; i>=0; --i ) {
		if ( len > 0 )	sum--;
		len--;
		len = max(len,a[i]);
	}
	cout << sum << '\n';
	return 0;
}

