#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n, m, k;
	cin >> n >> m >> k;
	if ( k < n )	cout << k+1 << ' ' << 1 << '\n';
	else {
		k -= n;
		m--;
		int row = n-(k/m);
		int col;
		if ( row%2 == 0 ) col = 2+(k%m);
		else	col = 1+m-(k%m);
		cout << row << ' ' << col << '\n';
	}
	return 0;
}