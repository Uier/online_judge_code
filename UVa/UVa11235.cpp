#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string.h>
#define maxn 100005
#define move 100000
using namespace std;
int s[maxn], dif[maxn], cnt[maxn+move], ans, output[maxn];
struct ask {
	int l, r, id;
} que[maxn];
vector<ask> M;
inline bool cmp(ask x, ask y) {return x.l < y.l;}
inline bool mmo(ask x, ask y) {return x.r < y.r;}
inline void add(int i) {
	int x = ++cnt[i+move];
	dif[x]++;
	dif[x-1]--;
	ans = max(ans,x);
}
inline void rmv(int i) {
	int x = --cnt[i+move];
	dif[x]++;
	dif[x+1]--;
	if ( dif[ans] == 0 ) ans = x;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	while ( cin >> n && n && cin >> q ) {
		for ( int i=1; i<=n; ++i )	cin >> s[i];
		for ( int i=1; i<=q; ++i ) {
			cin >> que[i].l >> que[i].r;
			que[i].id = i;
		}
		sort(que+1,que+1+q,cmp);
		int m = sqrt(n), pt = 1;
		if ( m*m < n )	m++;
		for ( int i=1; i<=n; i+=m ) {
			M.clear();
			while ( pt <= q && que[pt].l < i+m )
				M.emplace_back(que[pt++]);
			if ( M.empty() )	continue;
			sort(M.begin(),M.end(),mmo);
			memset(cnt,0,sizeof(cnt));
			memset(dif,0,sizeof(int)*(ans+1));
			ans = 0;
			int ptl = M[0].l+1, ptr = M[0].l;
			for ( ask j : M ) {
				while ( ptl > j.l )	add(s[--ptl]);
				while ( ptl < j.l ) rmv(s[ptl++]);
				while ( ptr < j.r ) add(s[++ptr]);
				output[j.id] = ans;
			}
		}
		for ( int i=1; i<=q; ++i )
			cout << output[i] << '\n';
	}
	return 0;
}
