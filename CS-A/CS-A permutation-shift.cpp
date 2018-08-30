#include <iostream>
using namespace std;
int cnt[105];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, ans = 0;
	cin >> n;
	for ( int i=1, x; i<=n; ++i ) {
		cin >> x;
		x = ((x-i)+n)%n;
		if ( ++cnt[x] > cnt[ans] )	ans = x;
	}
	cout << cnt[ans] << '\n';
	return 0;
}

