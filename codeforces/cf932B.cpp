#include <iostream>
#include <vector>
using namespace std;
vector<int> a[10];
int hi(int n) {
	if ( n < 10 )	return n;
	long long aa = 1;
	while ( n ) {
		if ( n%10 != 0 )
			aa *= n%10;
		n /= 10;
	} 
	return hi(aa);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	for ( int i=1; i<=1000000; ++i )
		a[hi(i)].emplace_back(i);
	int q, l, r, k;
	cin >> q;
	while ( q-- && cin >> l >> r >> k ) {
		auto i = lower_bound(a[k].begin(),a[k].end(),l);
		auto j = lower_bound(a[k].begin(),a[k].end(),r);
//		for ( auto k=i; k<=j; ++k )
//			cout << *k << '\n';
//			cout << "#######ans";
		if ( *j == r )	cout << j-i+1 << '\n';
		else	cout << j-i << '\n';
	}
	return 0;
}

