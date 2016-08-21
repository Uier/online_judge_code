#include<bits/stdc++.h>
using namespace std;

bool pnt[2000005];
int dice[2000005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, max=2000, sum=0, ans=0;
    cin >> n;
    max *= n;
    
    for ( int i=0; i<max; i++ )
    {
        pnt[i] = false;
        dice[i] = 0;
    }
        
    pnt[0] = true;
        
    while ( n-- )
    {
        int a;
        cin >> a;
        sum += a;
        for ( int i=sum; i>=0; i-- )
        {
            if ( pnt[i] )
            {
                pnt[i+a] = true;
                if ( i >= max/2 )
                    break;
            }
        }
    }    
        
    for ( int i=0; i<=sum; i++ )
    {
        if ( pnt[sum/2-i] )
        {
            ans = sum/2-i;
            break;
        }
    }
    
    int x=ans;
    int y=sum-x;
    cout << x << ' ' << y << '\n';    
    
    return 0;
}
