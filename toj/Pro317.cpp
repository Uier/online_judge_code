#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, q;
    long long m;
    cin >> n >> m;
    int rl[n][n];
    for ( int i=0; i<n; i++ )
    {
        for ( int j=0; j<n; j++ )
            cin >> rl[j][i];
    }
    cin >> q;
    while ( q-- )
    {
        int x1, x2, y1, y2;
        bool sw[10001]={0};
        int nw[10001]={0};
        cin >> x1 >> y1 >> x2 >> y2;
        for ( int i=y1; i<=y2; i++ )
        {
            for ( int j=x1; j<=x2; j++ )
            {
                sw[rl[i][j]] = true;
                nw[rl[i][j]]++;    
            }
        }
        int all=0;
        long long sum=0, tc=1;
        for ( int i=0; i<10001; i++ )
        {
            if ( sw[i] )
            {
                while ( nw[i]-- )
                    tc *= 2;
                sum %= m;
                tc %= m;
                sum += tc;
                all++;
                tc = 1;
            }
        }
        sum -= (all%m);
        cout << sum%m << endl;
    }
    return 0;
}
