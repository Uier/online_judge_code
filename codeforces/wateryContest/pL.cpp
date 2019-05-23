#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string.h>
#include <cmath>
#define maxn 200005
#define int long long
using namespace std;
typedef pair<int,int> pii;
int arr[maxn];
int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for ( int i=0; i<n; ++i )	cin >> arr[i];
	int ans = arr[n-1], lim = arr[n-1];
	for ( int i=n-2; i>=0; --i ) {
		if ( lim <= 1 )	break;
		if ( arr[i] < lim ) {
			lim = arr[i];
			ans += arr[i];
		} else {
			lim--;
			ans += lim;
		}
	}
	cout << ans << '\n';
	return 0;
}

