#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string.h>
#include <cmath>
#define maxn 500005
using namespace std;
typedef pair<int,int> pii;
int p[maxn], sum[maxn];
int find(int x) {
	return (p[x]==x ? x : (p[x]=find(p[x])));
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for ( int i=1; i<=n; ++i )	p[i] = i, sum[i] = 1;
	for ( int i=0, x, y, z; i<m; ++i ) {
		cin >> x;
		if ( x == 0 )	continue;
		cin >> y;
		for ( int j=1; j<x; ++j ) {
			cin >> z;
			int ty = find(y), tz = find(z);
			if ( ty != tz ) {
				sum[ty] += sum[tz];
				p[tz] = ty;
			}
		}
	}
	for ( int i=1; i<=n; ++i )
		cout << sum[find(i)] << ' ';
	return 0;
}

