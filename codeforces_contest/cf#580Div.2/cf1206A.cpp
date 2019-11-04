#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, arr[205] = {0}, brr[205] = {0}, vis[405] = {0};
	cin >> n;
	for ( int i=0; i<n; ++i ) {
		cin >> arr[i];
		vis[arr[i]] = 1;
	}
	cin >> m;
	for ( int i=0; i<m; ++i ) {
		cin >> brr[i];
		vis[brr[i]] = 1;
	}
	for ( int i=0; i<n; ++i ) {
		for ( int j=0; j<m; ++j ) {
			if ( arr[i]+brr[j] >= 0 && arr[i]+brr[j] <= 400 && vis[arr[i]+brr[j]] == 0 ) {
				cout << arr[i] << ' ' << brr[j] << '\n';
				return 0;
			}
		}
	}
	return 0;
}