#include <iostream>
#define int long long 
using namespace std;
main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, s, a, b, c;
	cin >> t;
	while ( t-- && cin >> s >> a >> b >> c ) {
		int cnt = a*c;
		int cost = s/cnt;
		int ans = cost*(a+b);
		s -= cnt*cost;
		ans += s/c;
		cout << ans << '\n';
	}
	return 0;
}

