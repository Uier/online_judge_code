#include <iostream>
using namespace std;
int a[20];
long long p[20];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, tc = 1;
	while ( cin >> n ) {
		long long ans = 0;
		p[0] = 1;
		for ( int i=1; i<=n; i++ ) {
			cin >> a[i];
			p[i] = p[i-1] * a[i];
		}
		for ( int i=1; i<=n; i++ )
			for ( int j=i; j<=n; j++ ) {
				long long sum = 1;
				for ( int k=i; k<=j; k++ )
					sum *= a[k];
				ans = max(ans,sum);
			}
		cout << "Case #" << tc++ << ": The maximum product is ";
		cout << ans << ".\n\n";
	}
	return 0;
}

