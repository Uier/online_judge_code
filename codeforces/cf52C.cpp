#include <iostream>
#include <string.h>
#include <sstream>
#define maxn 200005
using namespace std;
const long long inf = 1LL<<62;
struct node {
	long long val, chg;
} seg[maxn*4];
void push(int l, int r, int d) {
	seg[d*2].chg += seg[d].chg;
	seg[d*2+1].chg += seg[d].chg;
	int mid = (l+r)/2;
	seg[d*2].val += seg[d].chg;
	seg[d*2+1].val += seg[d].chg;
	seg[d].chg = 0;
}
void build(int l, int r, int d) {
	if ( l == r ) {
		cin >> seg[d].val;
		return;
	}
	int mid = (l+r)/2;
	build(l,mid,d*2);
	build(mid+1,r,d*2+1);
	seg[d].val = min(seg[d*2].val,seg[d*2+1].val);
}
void modify(int a, int b, int x, int l, int r, int d) {
	if ( a > r || b < l )	return;
	if ( a <= l && b >= r ) {
		seg[d].chg += x;
		seg[d].val += x;
		return;
	}
	push(l,r,d);
	int mid = (l+r)/2;
	modify(a,b,x,l,mid,d*2);
	modify(a,b,x,mid+1,r,d*2+1);
	seg[d].val = min(seg[d*2].val,seg[d*2+1].val);
}
long long query(int a, int b, int l, int r, int d) {
	if ( a > r || b < l )	return inf;
	if ( a <= l && b >= r )	return seg[d].val;
	push(l,r,d);
	int mid = (l+r)/2;
	return min(query(a,b,l,mid,d*2),query(a,b,mid+1,r,d*2+1));
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	string s;
	cin >> n;
	build(0,n-1,1);
	cin >> q;
	getline(cin,s);
	while ( q-- ) {
		getline(cin,s);
		stringstream ss(s);
		int a[3], pt = 0;
		while ( ss >> a[pt] )	pt++;
		if ( pt == 2 ) {
			if ( a[0] <= a[1] )
				cout << query(a[0],a[1],0,n-1,1) << '\n';
			else
				cout << min(query(a[0],n-1,0,n-1,1),query(0,a[1],0,n-1,1)) << '\n';
		} else {
			if ( a[0] <= a[1] )
				modify(a[0],a[1],a[2],0,n-1,1);
			else {
				modify(a[0],n-1,a[2],0,n-1,1);
				modify(0,a[1],a[2],0,n-1,1);
			}
		}
	}
	return 0;
}
