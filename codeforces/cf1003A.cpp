#include <iostream>
using namespace std;
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int n;
	cin >> n;
	for ( int i=0,x; i<n; ++i ) {
		cin >> x;
		a[x]++;
	}
	int ans = 1;
	for ( int i=0; i<=100; ++i ) {
		if ( a[i] > a[ans] )	ans = i;
	}
	cout << a[ans] << '\n';
	return 0;
}

