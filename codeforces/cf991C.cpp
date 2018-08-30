#include <iostream>
using namespace std;
bool check(long long n, long long x) {
	long long a = 0, b = 0;
	while ( n >= x && n >= 10 ) {
		a += x;
		n -= x;
		if ( n < 10 ) break;
		b += n/10;
		n -= n/10;
	}
	a += n;
	return a >= b;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n;
	cin >> n;
	long long l = 1, r = n;
	while ( l < r ) {
		long long mid = (l+r)/2;
		if ( check(n,mid) ) r = mid;
		else l = mid;
		if ( l+1 == r ) {
			if ( check(n,l) ) r = l;
			else break;
		}
	}
	cout << r << '\n';
	return 0;
}

