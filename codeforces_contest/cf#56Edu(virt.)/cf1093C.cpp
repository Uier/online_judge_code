#include <iostream>
#define maxn 200005
using namespace std;
long long ans[maxn];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for ( int i=0; i<n/2; ++i )	cin >> ans[n-1-i];
	for ( int i=1; i<n/2; ++i ) {
		if ( ans[n-1-i] > ans[n-i] ) {
			ans[i] = ans[n-1-i]-ans[n-i];
			ans[n-1-i] = ans[n-i];
		}
		if ( ans[i] < ans[i-1] ) {
			ans[n-1-i] -= ans[i-1]-ans[i];
			ans[i] = ans[i-1];
		}
	}
	for ( int i=0; i<n; ++i )	cout << ans[i] << ' ';
	cout << '\n';
	return 0;
}

