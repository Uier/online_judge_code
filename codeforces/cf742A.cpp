#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, a[4] = {6,8,4,2};
	cin >> n;
	if ( n == 0 )	cout << 1 << '\n';
	else	cout << a[n%4] << '\n';
	return 0;
}

