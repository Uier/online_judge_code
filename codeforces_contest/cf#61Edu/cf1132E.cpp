#include <iostream>
using namespace std;
long long w, ans = 0, arr[8], k = 0;
void dfs(int x, int n, int l) {
	if ( k > w )	return;
	if ( x == n ) {
		if ( k > ans )	ans = k;
		return;
	}
	for ( int i=l; i<8; ++i ) {
		k += arr[i];
		dfs(x+1,n,i+1);
		k -= arr[i];
	}
}
main() {
	ios::sync_with_stdio(false);
	//   sync_with_YinHsuan(true);
	cin.tie(0);
	cin >> w;
	for ( int i=0; i<8; ++i )	cin >> arr[i];
	for ( int i=1; i<=8; ++i ) {
		dfs(0,i,0);
	}
	cout << ans << '\n';
	return 0;
}

