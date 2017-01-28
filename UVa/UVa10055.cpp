#include <iostream>
using namespace std;
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	long long a, b;
	while ( cin >> a >> b ) {
		if ( a > b )
			cout << a-b << '\n';
		else
			cout << b-a << '\n';
	}
	return 0;
}

