#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, x, y;
	char c;
	cin >> n >> c >> x >> y;
	int mn = min(x,y), mx = max(x,y);
	for ( int i=1; i<n; ++i ) {
		cin >> c >> x >> y;
		if ( c == '+' ) {
			mn = max(mn,min(x,y));
			mx = max(mx,max(x,y));
		} else {
			cout << (max(x,y)>=mx&&min(x,y)>=mn ? "YES\n" : "NO\n");
		}
	}
	return 0;
}

