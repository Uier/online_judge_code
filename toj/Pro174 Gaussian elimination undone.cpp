#include<iostream>
using namespace std;
int eq[1005][1005];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t, n;
	cin >> t;
	while ( t-- ) {
		cin >> n;
		for ( int i=0; i<n; ++i )
			for ( int j=0; j<=n; ++j )
				cin >> eq[i][j] >> '\n';
	}
	return 0;
}

