#include <iostream>
#define maxn 505
#define int long long
using namespace std;
int n, m, arr[maxn];
bool check(int x) {
	int cnt = 1, sum = 0;
	for ( int i=0; i<n; ++i ) {
		if ( arr[i] > x )	return true;
		sum += arr[i];
		if ( sum > x ) {
			sum = arr[i];
			cnt++;
		}
	}
	return cnt > m;
}
int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while ( t-- && cin >> n >> m ) {
		for ( int i=0; i<n; ++i )	cin >> arr[i];
		int l = 0, r = 5e9;
		while ( l < r ) {
			int mid = l+r>>1;
			if ( check(mid) )
				l = mid;
			else
				r = mid;
			if ( l+1 == r ) break;
		}
		bool mark[maxn] = {0};
		int sum = arr[n-1];
		for ( int i=n-2; i>=0; --i ) {
			sum += arr[i];
			if ( sum > r ) {
				mark[i] = true;
				sum = arr[i];
				m--;
			}
		}
		for ( int i=0; i<n&&m>1; ++i )
			if ( !mark[i] ) {
				mark[i] = true;
				m--;
			}
		cout << arr[0];
		if ( mark[0] )	cout << " /";
		for ( int i=1; i<n; ++i ) {
			cout << ' ' << arr[i];
			if ( mark[i] )	cout << " /";
		}
		cout << '\n';
	}
	return 0;
}
/*
2
9 3
100 200 300 400 500 600 700 800 900
5 4
100 100 100 100 100

3
9 3
9 8 1 7 6 2 3 4 5
3 2
1 2 1
8 4
10 2 10 2 15 20 1 30

*/
