#include <iostream>
using namespace std;
main() {
//    ios::sync_with_stdio(false);
//    cin.tie(0);
	long long n;
	cin >> n;
	if ( n == 1 || n == 2 )	cout << "-1\n";
	else  {
		n *= n;
		if ( n%2 )	cout << n/2 << ' ' << n/2+1 << '\n';
		else	cout << n/4-1 << ' ' << n/4+1 << '\n';
	}
	return 0;
}

