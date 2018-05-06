#include <iostream>
#include <string.h>
#include <algorithm>
#define maxn 100005
using namespace std;
typedef pair<int,int> pii;
struct bomb {
	int x, y, c;
} a[maxn];
struct process {
	int x, y, i;
} x_dir[maxn], y_dir[maxn];
bool cmp_x(process u, process v) {
	if ( u.x == v.x )	return u.y < v.y;
	return u.x < v.x;
}
bool cmp_y(process u, process v) {
	if ( u.y == v.y )	return u.x < v.x;
	return u.y < v.y;
}
int p[maxn], C[maxn], V[maxn];
int find(int x) {
	return (p[x] == x ? x : p[x] = find(p[x]));
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T, N, R, cnt = 0;
	cin >> T;
	while ( T-- && cin >> N >> R && ++cnt ) {
		for ( int i=0; i<N; ++i ) {
			cin >> a[i].x >> a[i].y >> a[i].c;
			p[i] = i;
			C[i] = a[i].c;
			x_dir[i].x = y_dir[i].x = a[i].x;
			x_dir[i].y = y_dir[i].y = a[i].y;
			x_dir[i].i = y_dir[i].i = i;
		}
		sort(x_dir,x_dir+N,cmp_x); // for x-dir
		sort(y_dir,y_dir+N,cmp_y); // for y-dir
		for ( int i=1; i<N; ++i ) //	union x-dir
			if ( x_dir[i].x == x_dir[i-1].x && x_dir[i].y-x_dir[i-1].y <= R ) {
				int u = x_dir[i].i, v = x_dir[i-1].i;
				p[find(u)] = find(v);
				C[find(u)] = min(C[find(u)],min(a[u].c,a[v].c));
			}
		for ( int i=1; i<N; ++i ) //	union y-dir
			if ( y_dir[i].y == y_dir[i-1].y && y_dir[i].x-y_dir[i-1].x <= R ) {
				int u = y_dir[i].i, v = y_dir[i-1].i;
				p[find(u)] = find(v);
				C[find(u)] = min(C[find(u)],min(a[u].c,a[v].c));
			}
		int sum = 0;
		for ( int i=0; i<N; ++i )
			if ( V[find(i)] != cnt ) {
				sum += C[find(i)];
				V[find(i)] = cnt;
			}
		cout << sum << '\n';
	}
	return 0;
}

