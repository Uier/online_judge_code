#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n, m, p;
	cin >> n >> m >> p;
	long long b = n-m;
	n %= p;
	m %= p;
	b %= p;
	n = (n*m)%p;
	n = (n*b)%p;
	cout << n << '\n';
	return 0;
}

