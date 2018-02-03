#include <iostream>
#include <queue>
#include <string.h>
#define maxn 10005
using namespace std;
typedef pair<int,int> pii;
pii seg[maxn*4];
priority_queue<int> PQ[maxn];
void build(int l, int r, int d) {
	if ( l == r )	seg[d] = 
}
void INS(int l, int r, int d, int x, int v) {
	if ( l > x || r < x )	return;
	if ( l == r && l == x )	{
		PQ[d].push(v);
		seg[d].first = PQ[d].top();
		seg[d].second = d;
		return;
	}
	int mid = (l+r)/2;
	INS(l,mid,d*2,x,v);
	INS(mid+1,r,d*2+1,x,v);
	if ( seg[d*2+1].first > seg[d*2].first ) {
		seg[d].first = seg[d*2+1].first;
		seg[d].second = seg[d*2+1].second;
	} else {
		seg[d].first = seg[d*2].first;
		seg[d].second = seg[d*2].second;
	}
}
pii QUE(int a, int b, int l, int r, int d) {
	if ( l > b || r < a )	return 0;
	if ( l <= a && r >= b )	return seg[d];
	int mid = (l+r)/2;
	return max(QUE(a,b,l,mid,d*2),QUE(a,b,mid+1,r,d*2+1));
}
void DEL(int l, int r, int d, int x) {
	if ( l == r && r == x ) {
		if 
	}
}
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int N, Q;
	cin >> N >> Q;
	memset(seg,-1,sizeof seg);
	while ( Q-- ) {
		int a, b, c;
		cin >> a >> b >> c;
		if ( a == 0 )
			insert(0,N,0,b,c);
		else {
			pii tmp = QUE(b,c,0,N,0);
			cout << tmp.first << '\n';
			DEL(0,N,0,tmp.second);
		}
	}
	return 0;
}

