#include <iostream>
#include <vector>
#define maxn 100005
using namespace std;
typedef pair<int,int> pii;
vector<pii> x, y;
struct node {
	int val, chg, tag;
} seg[maxn*4];
void push(int l, int r, int d) {
	seg[d<<1].chg += seg[d].chg;
	seg[d<<1|1].chg += seg[d].chg;
	seg[d<<1].val += seg[d].chg;
	seg[d<<1|1].val += seg[d].chg;
	seg[d].chg = 0;
}
void build(int l, int r, int d) {
	if ( l == r ) {
		seg[d].val = 0;
		seg[d].chg = 0;
		seg[d].tag = l;
		return;
	}
	int mid = l+r>>1;
	build(l,mid,d<<1);
	build(mid+1,r,d<<1|1);
	if ( seg[d<<1].val >= seg[d<<1|1].val ) {
		seg[d].val = seg[d<<1].val;
		seg[d].tag = seg[d<<1].tag;
	} else {
		seg[d].val = seg[d<<1|1].val;
		seg[d].tag = seg[d<<1|1].tag;
	}
}
void modify(int a, int b, int l, int r, int d) {
	if ( a > r || b < l )	return;
	if ( a <= l && b >= r ) {
		seg[d].val += 1;
		seg[d].chg += 1;
		return;
	}
	push(l,r,d);
	int mid = l+r>>1;
	modify(a,b,l,mid,d<<1);
	modify(a,b,mid+1,r,d<<1|1);
	if ( seg[d<<1].val >= seg[d<<1|1].val ) {
		seg[d].val = seg[d<<1].val;
		seg[d].tag = seg[d<<1].tag;
	} else {
		seg[d].val = seg[d<<1|1].val;
		seg[d].tag = seg[d<<1|1].tag;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t, p, q, cs = 1;
	cin >> t;
	while ( t-- && cin >> p >> q ) {
		x.clear();
		y.clear();
		for ( int i=0; i<p; ++i ) {
			int a, b;
			char c;
			cin >> a >> b >> c;
			if ( c == 'N' ) {
				y.emplace_back(pii{b+1,q});
			} else if ( c == 'S' ) {
				y.emplace_back(pii{0,b-1});
			} else if ( c == 'E' ) {
				x.emplace_back(pii{a+1,q});
			} else { // c == 'W'
				x.emplace_back(pii{0,a-1});
			}
		}
		build(1,q+1,1);
		for ( pii i : x )
			modify(i.first+1,i.second+1,1,q+1,1);
		int ansx = seg[1].tag;
		build(1,q+1,1);
		for ( pii i : y )
			modify(i.first+1,i.second+1,1,q+1,1);
		int ansy = seg[1].tag;
		cout << "Case #" << cs++ << ": " << ansx-1 << ' ' << ansy-1 << '\n';
	}
	return 0;
}

