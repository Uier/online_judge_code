#include <iostream>
#include <math.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n, m;
	while ( cin >> n && n ) {
		m = sqrt(n);
		if ( m*m == n )	cout << "yes\n";
		else	cout << "no\n";
	}
	return 0;
}

