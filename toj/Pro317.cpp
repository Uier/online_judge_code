#include<bits/stdc++.h>
int rl[1005][1005], nw[10001];
long long cnt[1000100];
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
    int n, q;
    long long m;
    cin >> n >> m;
    for ( int i=0; i<n; i++ )
        for ( int j=0; j<n; j++ )
            cin >> rl[j][i];
    cnt[0] = 1;
	for ( int i=1; i<=n*n; i++ )
		cnt[i] = (cnt[i-1]*2)%m;
    cin >> q;
    while ( q-- ) {
        int x1, x2, y1, y2, all=0;
        cin >> x1 >> y1 >> x2 >> y2;
        if ( x1 > x2 )	swap(x1,x2);
        if ( y1 > y2 )	swap(y1,y2);
        memset(nw,0,sizeof(nw));
        for ( int i=y1; i<=y2; i++ )
            for ( int j=x1; j<=x2; j++ )
                nw[rl[i][j]]++;
        long long sum=0;
        for ( int i=0; i<10001; i++ ) {
            if ( nw[i] ) {
                sum += cnt[nw[i]];
                sum %= m;
                all++;
            }
        }
        sum -= (all%m);
        cout << sum%m << '\n';
    }
    return 0;
}
