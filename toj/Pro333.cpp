#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, a, b;
	long long ans=0;
	cin >> n >> a;
	if ( n != 1 )
		for ( int i=0; i<n-1; i++ ) {
			cin >> b;
			if ( a-b > 0 )
		    	ans += a-b;
			a = b;
		}
	cout << ans+a << '\n';
	return 0;
}
