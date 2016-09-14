#include <iostream>
using namespace std;
int a[3005][3005], b[3005][3005], n, m, q;
int sum(int l, int x) {
    if ( x > 0 )
        return a[l][x]+sum(l,x-(x&-x));
    return 0;
}
void add(int l, int x, int v) {
    if ( x > m )
        return;
    a[l][x] += v;
    add(l,x+(x&-x),v);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for ( int i=1; i<=n; i++ )
        for ( int j=1; j<=m; j++ ) {
            cin >> b[i][j];
            add(i,j,b[i][j]);
        }
    cin >> q;
    while ( q-- ) {
        char c;
        cin >> c;
        if ( c == 'C' ) {
            int t, u, v;
            cin >> t >> u >> v;
            add(t,u,v-b[t][u]);
            b[t][u] = v;
        }
        else {
            int x1, y1, x2, y2, ans=0;
            cin >> x1 >> y1 >> x2 >> y2;
            if ( x1 > x2 )    swap(x1,x2);
            if ( y1 > y2 )    swap(y1,y2);
            for ( int i=x1; i<=x2; i++ )
                ans += sum(i,y2)-sum(i,y1-1);
            cout << ans << '\n';
        }
    }
    return 0;
}
