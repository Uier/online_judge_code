#include <iostream>
#include <algorithm>
#define maxn 50005
using namespace std;
struct node {
	int x, y;
} arr[maxn], H[maxn];
inline bool cross(node o, node a, node b) {
	return (o.x-a.x)*(o.y-b.y)-(o.y-a.y)*(o.x-b.x) > 0;
}
inline bool cmp(node a, node b) {
	return (a.x < b.x) || (a.x == b.x && a.y < b.y);
}
inline int dist(node a, node b) {
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m = 0, ans = 0;
	cin >> n;
	for ( int i=0; i<n; ++i )
		cin >> arr[i].x >> arr[i].y;
	sort(arr,arr+n,cmp);
	for ( int i=0; i<n; ++i ) {
		while ( i >= 2 && cross(H[m-2],H[m-1],arr[i]) )	m--;
		H[m++] = arr[i];
	}
	for ( int i=n-2, j=m+1; i>=0; --i ) {
		while ( m >= j && cross(H[m-2],H[m-1],arr[i]) )	m--;
		H[m++] = arr[i];
	}
	m--;
	for ( int i=0; i<m; ++i )
		for ( int j=i+1; j<m; ++j )
			ans = max(ans,dist(H[i],H[j]));
	cout << ans << '\n';
	return 0;
}

