#include <iostream>
#include <vector>
#define maxn 50005
using namespace std;
vector<int> G[maxn];
int W[maxn], fa[maxn], in[maxn], out[maxn], A[maxn*2], cnt;
void dfs(int x) {
    in[x] = cnt;
    A[cnt++] = W[x];
    for ( int i : G[x] )
        if ( i != fa[x] ) {
            fa[i] = x;
            dfs(i);
        }
    out[x] = cnt;
    A[cnt++] = -W[x];
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, a, b;
    cin >> n >> m;
    for ( int i=1; i<n; ++i ) {
        cin >> a >> b;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }
    for ( int i=1; i<=n; ++i )
        cin >> W[i];
    fa[1] = -1;
    dfs(1);
    int ans = 0;
    while ( m-- ) {
        char c;
        cin >> c >> a;
        if ( c == 'C' ) {
            cin >> b;
            A[in[a]] = b;
            A[out[a]] = -b;
        } else
            for ( int i=0; i<=in[a]; ++i )
                ans += A[i];
    }
    cout << ans << '\n';
    return 0;
}

