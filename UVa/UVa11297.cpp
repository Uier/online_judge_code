#include <iostream>
#define maxn 505
using namespace std;
typedef pair<int,int> pii;
struct seg_1d {
	int H[maxn*4], L[maxn*4];
	void build(int l, int r, int d) {
		if ( l == r ) {
			cin >> H[d];	L[d] = H[d];
			return;
		}
		int mid = l+r>>1;
		build(l,mid,d<<1);
		build(mid+1,r,d<<1|1);
		H[d] = max(H[d<<1],H[d<<1|1]);
		L[d] = min(L[d<<1],L[d<<1|1]);
	}
	void modify(int l, int r, int d, int x, int val) {
		if ( x < l || r < x )	return;
		if ( l == r && l == x )	{
			H[d] = L[d] = val;
			return;
		}
		int mid = l+r>>1;
		modify(l,mid,d<<1,x,val);
		modify(mid+1,r,d<<1|1,x,val);
		H[d] = max(H[d<<1],H[d<<1|1]);
		L[d] = min(L[d<<1],L[d<<1|1]);
	}
	pii query(int a, int b, int l, int r, int d) {
		if ( a > r || b < l )	return pii{-1,2e9};
		if ( a <= l && r <= b ) return pii{H[d],L[d]};
		int mid = l+r>>1;
		pii t1 = query(a,b,l,mid,d<<1), t2 = query(a,b,mid+1,r,d<<1|1);
		return pii{max(t1.first,t2.first),min(t1.second,t2.second)};
	}
	void merge(const seg_1d &a, const seg_1d &b, int l, int r, int d) {
		H[d] = max(a.H[d],b.H[d]);
		L[d] = min(a.L[d],b.L[d]);
		if ( l == r )	return;
		int mid = l+r>>1;
		merge(a,b,l,mid,d<<1);
		merge(a,b,mid+1,r,d<<1|1);
	}
	void print(int l, int r, int d) {
		if ( l == r ) {
			cout << H[d] << ' ' << L[d] << '\t';
			return;
		}
		int mid = l+r>>1;
		print(l,mid,d<<1);
		print(mid+1,r,d<<1|1);
	}
};
struct seg_2d {
	seg_1d seg[maxn*4];
	void build(int rl, int rr, int cl, int cr, int d) {
		if ( rl == rr ) {
			seg[d].build(cl,cr,1);
			return;
		}
		int mid = rl+rr>>1;
		build(rl,mid,cl,cr,d<<1);
		build(mid+1,rr,cl,cr,d<<1|1);
		seg[d].merge(seg[d<<1],seg[d<<1|1],cl,cr,1);
	}
	void modify(int rl, int rr, int cl, int cr, int d, int y, int x, int val) {
		if ( rl > y || rr < y )	return;
		if ( rl == rr && rl == y ) {
			seg[d].modify(cl,cr,1,x,val);
			return;
		}
		int mid = rl+rr>>1;
		modify(rl,mid,cl,cr,d<<1,y,x,val);
		modify(mid+1,rr,cl,cr,d<<1|1,y,x,val);
		seg[d].merge(seg[d<<1],seg[d<<1|1],cl,cr,1);
	}
	pii query(int rl, int rr, int cl, int cr, int d, int y1, int x1, int y2, int x2) {
		if ( rl > y2 || rr < y1 )	return pii{-1,2e9};
		if ( y1 <= rl && rr <= y2 )	return seg[d].query(x1,x2,cl,cr,1);
		int mid = rl+rr>>1;
		pii t1 = query(rl,mid,cl,cr,d<<1,y1,x1,y2,x2);
		pii t2 = query(mid+1,rr,cl,cr,d<<1|1,y1,x1,y2,x2);
		return pii{max(t1.first,t2.first),min(t1.second,t2.second)};
	}
	void print(int rl, int rr, int cl, int cr, int d) {
		if ( rl == rr ) {
			seg[d].print(cl,cr,1);
			cout << '\n';
			return;
		}
		int mid = rl+rr>>1;
		print(rl,mid,cl,cr,d<<1);
		print(mid+1,rr,cl,cr,d<<1|1);
	}
} T;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, q, a, b, c, d;
	char k;
	cin >> n;
	T.build(1,n,1,n,1);
	cin >> q;
	while ( q-- && cin >> k ) {
		if ( k == 'q' ) {
			cin >> a >> b >> c >> d;
			pii tmp = T.query(1,n,1,n,1,a,b,c,d);
			cout << tmp.first << ' ' << tmp.second << '\n';
		} else {
			cin >> a >> b >> c;
			T.modify(1,n,1,n,1,a,b,c);
		}
		// debug
//		T.print(1,n,1,n,1);
	}
	return 0;
}
