#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n, m;
	while ( cin >> n >> m ) {
		long long x = 1, sum = n;
		while ( sum <= m ) {
			sum += n+x;
			x++;
		}
		cout << x << '\n';
	}
	return 0;
}

