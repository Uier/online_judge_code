#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string.h>
#include <cmath>
#define int long long
#define maxn 200005
using namespace std;
typedef pair<int,int> pii;
int arr[maxn];
int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	for ( int i=0; i<n; ++i )	cin >> arr[i];
	sort(arr,arr+n);
	int kk = k+1;
	int d = m/kk;
	int ans = d*arr[n-1]*k+d*arr[n-2] + (m%kk)*arr[n-1];
	cout << ans << '\n';
	return 0;
}

