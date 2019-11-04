#include <bits/stdc++.h>
#define maxn 305
using namespace std;
int arr[maxn][maxn];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for ( int i=1; i<=n; ++i )
		for ( int j=1; j<=n; ++j )
			arr[i][j] = n*(i-1)+j;
	for ( int i=1; i<=n; ++i ) {
		int tmp[2] = {i,n-i+1}, cur = 0;
		for ( int j=1; j<=n; ++j, cur^=1 )
			cout << arr[j][tmp[cur]] << ' ';
		cout << '\n';
	}
	// if ( n&1 ) {
	// } else {

	// }
	return 0;
}