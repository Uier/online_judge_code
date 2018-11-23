#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, n, cs = 1;
	cin >> t;
	while ( t-- && cin >> n ) {
		bool flag = false;
		int m = n, sum = 0;
		for ( int i=0; i<10000; ++i ) {
			while ( m ) {
				sum += (m%10)*(m%10);
				m /= 10;
			}
			if ( sum == 1 ) {
				flag = true;
				break;
			}
			m = sum, sum = 0;
		}
		if ( flag )
			cout << "Case #" << cs++ << ": " << n << " is a Happy number.\n";
		else
			cout << "Case #" << cs++ << ": " << n << " is an Unhappy number.\n";
	}
	return 0;
}

