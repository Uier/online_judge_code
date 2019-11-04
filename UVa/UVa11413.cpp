#include <iostream>
#define maxn 1005
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
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while ( cin >> n >> m ) {
		for ( int i=0; i<n; ++i )	cin >> arr[i];
		int l = 0, r = 1e9;
		while ( l < r ) {
			int mid = l+r>>1;
			if ( check(mid) )	l = mid;
			else	r = mid;
			if ( l+1 == r )	break;
		}
		cout << r << '\n';
	}
	return 0;
}
/*
5 3
1 2 3 4 5
3 2
4 78 9
*/