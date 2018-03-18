#include <iostream>
using namespace std;

int main() {
//  ios::sync_with_stdio(false);
//  cin.tie(0);
	int l, r, a;
	cin >> l >> r >> a;
	if ( l > r )	swap(l,r);
	int res = r-l;
	if ( a > res )	cout << r*2+(a-res)/2*2 << '\n';
	else {
		cout << (l+a)*2 << '\n';
	}
	return 0;
}

