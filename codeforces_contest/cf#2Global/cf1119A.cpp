#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <string.h>
#include <map>
#define maxn 300005
using namespace std;
int arr[maxn];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for ( int i=1; i<=n; ++i )	cin >> arr[i];
	int ans = 0;
	for ( int i=n; i>0; --i ) {
		if ( arr[i] != arr[1] ) {
			ans = i-1;
			break;
		}
	}
	for ( int i=1; i<n; ++i ) {
		if ( arr[i] != arr[n] ) {
			ans = max(ans,n-i);
			break;
		}
	}
	cout << ans << '\n';
	return 0;
}

