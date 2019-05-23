#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	//   sync_with_YinHsuan(true);
	cin.tie(0);
	int n, ans = 0, mx = 0;
	cin >> n;
	for ( int i=0, x; i<n; ++i ) {
		cin >> x;
		mx = max(mx,x);
		if ( mx == i+1 ) {
			ans++;
			mx = 0;
		}
	} 
	cout << ans << '\n';
	return 0;
}

