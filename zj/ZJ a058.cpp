#include <iostream>
using namespace std;
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int n, x;
	while ( cin >> n ) {
		int a=0, b=0, c=0;
		while ( n-- ) {
			cin >> x;
			if ( x%3 == 0 )	a++;
			else if ( x%3 == 1 ) b++;
			else c++;
		}
		cout << a << ' ' << b << ' ' << c << '\n';
	}
	return 0;
}

