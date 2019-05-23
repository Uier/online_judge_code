#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string.h>
#include <cmath>
#define maxn 100005
using namespace std;
typedef pair<int,int> pii;
int arr[maxn];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, mx = 0;
	cin >> n;
	for ( int i=0; i<n; ++i ) {
		cin >> arr[i];
		mx = max(mx,arr[i]);
	}
	int ans = 0;
	for ( int i=0; i<n; ++i ) {
		if ( arr[i] == mx ) {
			int j = i, cnt = 0;
			while ( j < n && arr[j] == mx ) {
				cnt++;
				j++;
			}
			ans = max(ans,cnt);
			i = j;
		}
	}
	cout << ans << '\n';
	return 0;
}

