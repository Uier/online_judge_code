#include <iostream>
using namespace std;
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int k, r, ans=1, j;
	cin >> k >> r;
	j = k;
	while ( j%10 != r && j%10 != 0 ) {
		j += k;
		ans++;
	}
	cout << ans << '\n';
	return 0;
}

