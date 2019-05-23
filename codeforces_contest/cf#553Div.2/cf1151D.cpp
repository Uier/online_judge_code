#include <iostream>
#include <algorithm>
#define maxn 100005
#define int long long
using namespace std;
struct node {
	int x, y;
} arr[maxn], brr[maxn];
bool cmp(node a, node b) {
	return abs(a.x-a.y) > abs(b.x-b.y);
}
main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for ( int i=0; i<n; ++i )
		cin >> arr[i].x >> arr[i].y;
	sort(arr,arr+n,cmp);
	int pt1 = 0, pt2 = n-1;
	for ( int i=0; i<n; ++i ) {
		if ( arr[i].x > arr[i].y )	brr[pt1++] = arr[i];
		else	brr[pt2--] = arr[i];
	}
	int ans = 0;
	for ( int i=0; i<n; ++i )
		ans += brr[i].x*i+brr[i].y*(n-1-i);
		cout << ans << '\n';
	return 0;
}

