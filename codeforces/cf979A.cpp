#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n;
	cin >> n;
	n++;
	if ( n == 1 )	cout << 0 << '\n';
	else cout << (n%2==0 ? n/2 : n) << '\n';
	return 0;
}

