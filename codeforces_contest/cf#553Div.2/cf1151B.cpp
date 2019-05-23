#include <iostream>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
using namespace std;
int arr[505][505];
int cnt[505][1024];
vector<int> ans;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for ( int i=1; i<=n; ++i ) {
		for ( int j=1; j<=m; ++j ) {
			cin >> arr[i][j];
			if ( i == 1 )	cnt[i][arr[i][j]] = j;
			else {
				for ( int k=0; k<1024; ++k ) {
					if ( cnt[i-1][k] ) {
						cnt[i][k^arr[i][j]] = j;
					}
				}
			}
		}
	}
	for ( int i=1023; i>0; --i ) {
		if ( cnt[n][i] ) {
			cout << "TAK\n";
			for ( int j=n; j>0; --j ) {
				ans.emplace_back(cnt[j][i]);
				i ^= arr[j][cnt[j][i]];
			}
			for ( int i=0; i<n; ++i ){
				cout << ans[n-1-i] << ' ';
			}
			return 0;
		}
	}
	cout << "NIE\n";
	return 0;
}

