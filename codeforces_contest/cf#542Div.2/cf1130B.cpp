#include <iostream>
#include <math.h>
#define maxn 100005
#define int long long
using namespace std;
int arr[maxn][2];
main() {
	ios::sync_with_stdio(false);
	//   sync_with_YinHsuan(true);
	cin.tie(0);
	int n, ans = 0, st1 = 1, st2 = 1;
	cin >> n;
	for ( int i=0, x; i<n*2; ++i ) {
		cin >> x;
		if ( arr[x][0] )	arr[x][1] = i+1;
		else	arr[x][0] = i+1;
	}
	for ( int i=1; i<=n; ++i ) {
		if ( abs(arr[i][0]-st1)+abs(arr[i][1]-st2) < abs(arr[i][1]-st1)+abs(arr[i][0]-st2) ) {
			ans += abs(arr[i][0]-st1)+abs(arr[i][1]-st2);
			st1 = arr[i][0];
			st2 = arr[i][1];
		} else {
			ans += abs(arr[i][1]-st1)+abs(arr[i][0]-st2);
			st1 = arr[i][1];
			st2 = arr[i][0];
		}
	} 
	cout << ans << '\n';
	return 0;
}

