#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, odd = 0, even = 0;
	cin >> n;
//	if ( n == 1 )	return cout << "1 \n", 0;
//	if ( n == 2 )	return cout << "1 2\n", 0;
//	if ( n == 3 )	return cout << "1 1 3\n", 0;
	int pt = 1;
	while ( n > 4 ) {
		if ( n&1 ) {
			odd = n/2+1;
			even = n/2;
		} else	odd = even = n/2;
		for ( int i=0; i<odd; ++i )	cout << pt << ' ';
		n >>= 1;
		pt <<= 1;
	}
	if ( n == 1 )	cout << 1*pt << '\n';
	else if ( n == 2 )	cout << 1*pt << ' ' << 2*pt << '\n';
	else if ( n == 3 )	cout << 1*pt << ' ' << 1*pt << ' ' << 3*pt << '\n';
	else if ( n == 4 )	cout << 1*pt << ' ' << 1*pt << ' ' << 2*pt << ' ' << 4*pt << '\n';
	cout << '\n';
//	int two = (even+1)/2, pt = 1;
//	for ( int i=0; i<two; ++i )	cout << 2 << ' ';
//	if ( even == 3 )	return cout << 6 << '\n', 0;
//	even -= two;
//	pt++;
//	while ( even > 0 ) {
//		two = (even+1)/2;
//		for ( int i=0; i<two; ++i )	cout << (1<<pt) << ' ';
//		even -= two;
//		pt++;
//	}
	return 0;
}

