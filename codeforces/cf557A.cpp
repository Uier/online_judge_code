#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, mn[4], mx[4];
	cin >> n;
	for ( int i=1; i<=3; ++i )	cin >> mn[i] >> mx[i];
	int one = 0, two = 0, thr = 0;
	thr = mn[3];
	n -= mn[3];
	two = mn[2];
	n -= mn[2];
	if ( n <= mx[1] ) {
		cout << n << ' ' << two << ' ' << thr << '\n';
		return 0;
	}
	n -= mx[1];
	one = mx[1];
	if ( n <= mx[2]-two ) {
		cout << one << ' ' << n+two << ' ' << thr << '\n';
		return 0;
	}
	n -= mx[2]-two;
	two = mx[2];
	cout << one << ' ' << two << ' ' << n+thr << '\n';
	return 0;
}

