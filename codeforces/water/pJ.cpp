#include <iostream>
using namespace std;
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int n, a = 0, b = 0;
	cin >> n;
	for ( int i=0, x, y; i<n; ++i ) {
		cin >> x >> y;
		if ( x > 0 )	a++;
		else	b++;
	}
	if ( a <= 1 || b <= 1 )	cout << "Yes\n";
	else	cout << "No\n";
	return 0;
}

