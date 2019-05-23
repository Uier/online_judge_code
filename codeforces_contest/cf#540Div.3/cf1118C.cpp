#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int cnt[1005], M[21][21];
vector<int> arr;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for ( int i=0, x; i<n*n; ++i ) {
		cin >> x;
		if ( !cnt[x] )	arr.emplace_back(x);
		cnt[x]++;
	}
	if ( n&1 ) {
		bool fail = 1;
		for ( int i : arr )	{
			if ( cnt[i]&1 ) {
				M[n/2][n/2] = i;
				cnt[i]--;
				fail = 0;
				break;
			}
		}
		int pt = 0;
		for ( int i=0; i<2; ++i )
			for ( int j=0; j<n/2; ++j ) {
				while ( pt < arr.size() && cnt[arr[pt]]%4 != 2 )	pt++;
				if ( pt >= arr.size() )	continue;
				if ( i == 0 )
					M[j][n/2] = M[n-1-j][n/2] = arr[pt];
				else
					M[n/2][j] = M[n/2][n-1-j] = arr[pt];
				cnt[arr[pt]] -= 2;
			}
		if ( fail )	return cout << "NO\n", 0;
		pt = 0;
		for ( int i=0; i<n; ++i ) {
			for ( int j=0; j<n; ++j ) {
				if ( M[i][j] )	continue;
				while ( pt < arr.size() && cnt[arr[pt]] < 4 )	pt++;
				if ( pt >= arr.size() || cnt[arr[pt]]%4 )	return cout << "NO\n", 0;
				if ( i == n/2 || j == n/2 ) {
					M[i][j] = M[n-1-i][j] = arr[pt];
					M[j][i] = M[j][n-1-i] = arr[pt];
				} else {
					M[i][j] = M[n-1-i][j] = arr[pt];
					M[i][n-1-j] = M[n-1-i][n-1-j] = arr[pt];
				}
				cnt[arr[pt]] -= 4;				
			}
		}
	} else {
		int pt = 0;
		for ( int i=0; i<n; ++i ) {
			for ( int j=0; j<n; ++j ) {
				if ( M[i][j] )	continue;
				while ( pt < arr.size() && cnt[arr[pt]] < 4 )	pt++;
				if ( pt >= arr.size() || cnt[arr[pt]]%4 )	return cout << "NO\n", 0;
				M[i][j] = M[n-1-i][j] = arr[pt];
				M[i][n-1-j] = M[n-1-i][n-1-j] = arr[pt];
				cnt[arr[pt]] -= 4;
			}
		}
	}
	cout << "YES\n";
	for ( int i=0; i<n; ++i ) {
		for ( int j=0; j<n; ++j )
			cout << M[i][j] << ' ';
		cout << '\n';
	}
	return 0;
}
