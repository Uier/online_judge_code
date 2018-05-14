#include <iostream>
#include <queue> 
#define maxn 200005
using namespace std;
int seg[maxn*4];
inline void build(int l, int r, int d) {
    if ( l == r ) {
        cin >> seg[d];
        return;
    }
    int mid = (l+r)/2;
    build(l,mid,d*2);
    build(mid+1,r,d*2+1);
    seg[d] = max(seg[d*2],seg[d*2+1]);
}
inline void add(int a, int l, int r, int d, int v) {
    if ( a > r || a < l )    return;
    if ( l == r && l == a ) {
        seg[d] += v;
        return;
    }
    int mid = (l+r)/2;
    add(a,l,mid,d*2,v);
    add(a,mid+1,r,d*2+1,v);
    seg[d] = max(seg[d*2],seg[d*2+1]);
}
inline void package(int a, int b, int l, int r, int d, int v) {
    if ( a > r || b < l || seg[d] < v )    return;
    if ( l == r ) {
        seg[d] %= v;
        return;
    }
    int mid = (l+r)/2;
    package(a,b,l,mid,d*2,v);
    package(a,b,mid+1,r,d*2+1,v);
    seg[d] = max(seg[d*2],seg[d*2+1]);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, Q, a, b, c, d;
    cin >> N;
    build(0,N-1,1);
    cin >> Q;
    while ( Q-- ) {
        cin >> a;
        if ( a == 1 ) {
            cin >> b >> c;
            add(c,0,N-1,1,b);
        } else if ( a == 2 ) {
            cin >> b >> c >> d;
            package(b,c,0,N-1,1,d);
        } else    cout << seg[1] << '\n';
    } 
    return 0;
}
