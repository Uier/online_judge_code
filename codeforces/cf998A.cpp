#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
pii a[10];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, tmp = 0, x;
	bool dis = true;
	cin >> n >> tmp;
	a[1] = pii{tmp,1};
	for ( int i=2; i<=n; ++i ) {
		cin >> x;
		if ( tmp != x )	dis = false;
		a[i] = pii{x,i};
	}
	if ( n == 1 )	cout << -1 << '\n';
	else {
		if ( n == 2 && dis )	cout << -1 << '\n';
		else {
			sort(a+1,a+1+n);
			cout << 1 << '\n';
			cout << a[1].second << '\n';
		}
	}
	return 0;
}

