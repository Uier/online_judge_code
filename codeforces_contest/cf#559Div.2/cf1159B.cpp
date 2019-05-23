#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string.h>
#include <cmath>
#define maxn 300005
using namespace std;
typedef pair<int,int> pii;
int arr[maxn];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for ( int i=0; i<n; ++i )	cin >> arr[i];
	int l = 0, r = n-1, ans = 1e9;
	while ( l < r ) {
		ans = min(ans,min(arr[l],arr[r])/(r-l));
		if ( min(arr[l+1],arr[r]) < min(arr[l],arr[r-1]) )	l++;
		else	r--;
	}
	cout << ans << '\n';
	return 0;
}

