#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <string.h>
#include <map>
#define maxn 100005
#define int long long
using namespace std;
int s[maxn];
vector<int> d, z;
struct nnnn {
	int sz, i;
} que[maxn];
inline bool cmp(nnnn x, nnnn y) {
	return x.sz < y.sz;
}
inline bool cmpidx(nnnn x, nnnn y) {
	return x.i < y.i;
}
main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n;
	for ( int i=1; i<=n; ++i )	cin >> s[i];
	sort(s+1,s+1+n);
	for ( int i=1; i<n; ++i ) {
		d.emplace_back(s[i+1]-s[i]);
	}
	sort(d.begin(),d.end());
	z.emplace_back(1);
	for ( int i=1; i<d.size(); ++i ) {
		if ( d[i] == d[i-1]	)	z.back()++;
		else	z.emplace_back(1);
	}
	d.resize(unique(d.begin(),d.end())-d.begin());
	int l, r;
	cin >> q;
	for ( int i=0; i<q; ++i ) {
		cin >> l >> r;
		que[i] = nnnn{r-l+1,i};
	}
	sort(que,que+q,cmp);
	int ptr = 0, ans = 0, pre;
	for ( int i=0; i<q; ++i ) {
		int sz = que[i].sz;
		ans *= sz-pre
		for ( ; ptr<d.size()&&d[ptr]<sz; ++ptr ) {
			ans += (sz-d[ptr])*z[ptr];
		}
		pre = sz;
		que[i].sz = sz*n-ans;
	}
	sort(que,que+q,cmpidx);
	cout << que[0].sz;
	for ( int i=1; i<q; ++i )	cout << ' ' << que[i].sz;
	cout << '\n';
	return 0;
}

