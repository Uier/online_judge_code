#include <iostream>
using namespace std;
int arr[10005], tar[10005][105];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, n, k;
	cin >> t;
	for ( int cnt=1; cnt<=t; ++cnt ) {
		cin >> n >> k;
		for ( int i=0; i<n; ++i )
			cin >> arr[i];
		tar[0][((arr[0]%k)+k)%k] = cnt;
		for ( int i=1; i<n; ++i )
			for ( int j=0; j<k; ++j )
				if ( tar[i-1][j] == cnt ) {
					tar[i][((j+arr[i])%k+k)%k] = cnt;
					tar[i][((j-arr[i])%k+k)%k] = cnt;
				}
		if ( tar[n-1][0] == cnt )	cout << "Divisible\n";
		else	cout << "Not divisible\n";
	}
	return 0;
}

