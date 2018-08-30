#include <iostream>
#include <algorithm>
#include <set>
#define maxn 200005
using namespace std;
typedef pair<long long,long long> pii;
struct edge {
	long long l, r;
	int id;
} seg[maxn];
set<pii> S;
int ans[maxn];
inline bool cmp(edge a, edge b) {return a.r < b.r;}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m >> seg[0].l >> seg[0].r;
	for ( int i=1; i<n; ++i ) {
		cin >> seg[i].l >> seg[i].r;
		long long prel = seg[i-1].l, prer = seg[i-1].r;
		seg[i-1].l = seg[i].l-prer;
		seg[i-1].r = seg[i].r-prel;
		seg[i-1].id = i-1;
	}
	for ( int i=1; i<=m; ++i ) {
		long long a;
		cin >> a;
		S.insert(pii{a,i});
	}
	sort(seg,seg+n-1,cmp);
	for ( int i=0; i<n-1; ++i ) {
		auto it = S.lower_bound(pii{seg[i].l,0});
		if ( it != S.end() && (*it).first <= seg[i].r ) {
			ans[seg[i].id] = (*it).second;
			S.erase(it);
		} else {
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n";
	for ( int i=0; i<n-1; ++i )
		cout << ans[i] << ' ';
	cout << '\n';
	return 0;
}

