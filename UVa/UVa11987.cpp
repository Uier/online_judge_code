#include <iostream>
#define maxn 100005
using namespace std;
int p[maxn*2], cnt[maxn], sum[maxn], n, m;
int find(int x) {return (p[x]==x ? x : (p[x]=find(p[x])));}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	while ( cin >> n >> m ) {
		for ( int i=1; i<=n; ++i )	sum[i] = i, cnt[i] = 1;
		for (int i=n+1; i<=n*2; ++i )	p[i-n] = p[i] = i;
		int tp, u, v;
		while ( m-- && cin >> tp ) {
			if ( tp == 1 || tp == 2 ) {
				cin >> u >> v;
				int tu = find(u), tv = find(v);
				if ( tu == tv )	continue;
				if ( tp == 1 ) { // union u v
					p[tu] = tv;
					cnt[tv-n] += cnt[tu-n];
					sum[tv-n] += sum[tu-n];
					cnt[tu-n] = sum[tu-n] = 0;
				} else { // move u to set that v is
					p[u] = tv;
					cnt[tu-n]--;
					sum[tu-n] -= u;
					cnt[tv-n]++;
					sum[tv-n] += u;
				}
			} else { // query
				cin >> u;
				u = find(u)-n;
				cout << cnt[u] << ' ' << sum[u] << '\n'; 
			}
		}
	}
	return 0;
}

