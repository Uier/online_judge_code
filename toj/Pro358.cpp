#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, x, a, b;
	bool ans=false;
	cin >> n >> x >> a >> b;
	if ( a == b )
		ans = true;
	for ( int i=0, k; i<n; i++ ) {
		cin >> k;
		if ( a*x == b*k )
			ans = true;
	}
	if ( ans )
		cout << "Yes\n";
	else	
		cout << "No\n";
	return 0;
}

