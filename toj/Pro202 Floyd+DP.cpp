#include <iostream>
using namespace std;
typedef pair<int,int> pii;
pii dp[101][101];
const int inf = 1e9;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, s, a, b, c, q;
    cin >> n >> m >> s;
    for ( int i=0; i<n; ++i )
        for ( int j=i+1; j<n; ++j )
            dp[i][j] = dp[j][i] = pii{inf,s};
    for ( int i=0; i<n; ++i )    dp[i][i] = pii{0,0};
    while ( m-- && cin >> a >> b >> c )
        if ( c < s )
            dp[a][b] = dp[b][a] = min(dp[a][b],pii{1,c});
    for ( int k=0; k<n; ++k )
        for ( int i=0; i<n; ++i )
            for ( int j=0; j<n; ++j )
                if ( dp[i][k].first < inf && dp[k][j].first < inf ) {
                	pii tmp;
                    int rem = s-dp[i][k].second;
                    if ( dp[k][j].second < rem )
                    	tmp = pii{dp[i][k].first,}
                    if ( tmp.second > 0 && tmp.second < s )    tmp.first--;
                    else    tmp.second = dp[k][j].second;
                    dp[i][j] = min(dp[i][j],tmp);
                }
    cin >> q;
    while ( q-- && cin >> a >> b )
        if ( a == b )    cout << 0 << '\n';
        else if ( dp[a][b].first == inf )    cout << "Impossible\n";
        else    cout << dp[a][b].first << '\n';
    return 0;
}
