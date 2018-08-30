#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, x, cnt = 0, a[1005];
	cin >> n;
	for ( int i=0; i<n; ++i ) {
		cin >> x;
		if ( x == 1 ) {
			cnt++;
			a[cnt] = 1;
		} else {
			a[cnt]++;
		}
	}
	cout << cnt << '\n';
	for ( int i=1; i<=cnt; ++i )
		cout << a[i] << ' ';
	cout << '\n';
	return 0;
}

