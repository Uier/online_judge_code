#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, cur = 0;
	cin >> n >> m;
	for ( int i=0, x; i<n; ++i ) {
		cin >> x;
		cur += x;
		cout << cur/m << ' ';
		cur %= m;
	}
	cout << '\n';
	return 0;
}

