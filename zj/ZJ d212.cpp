#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n, a[100] = {1,2};
	for ( int i=2; i<100; ++i )	a[i] = a[i-1]+a[i-2];
	while ( cin >> n )	cout << a[n-1] << '\n';
	return 0;
}

