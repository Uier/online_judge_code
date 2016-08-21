#include <bits/stdc++.h>
using namespace std;
int lcs[4003][4003], ta[4003], tb[4003], tra[4003], trb[4003];

int lcs_(int x, int y, int ta[], int tb[])
{
	for ( int i=0; i<=x; i++ )
	{
		for ( int j=0; j<=y; j++ )
			lcs[i][j] = 0;
	}

	for ( int i=1; i<=x; i++ )
    {
        for ( int j=1; j<=y; j++ )
        {
            if ( ta[i] == tb[j] )
                lcs[i][j] = lcs[i-1][j-1] + 1;
            else
                lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]); 
        }
    }

	return lcs[x][y];
}

int main()
{
    string sa, sb;
    cin >> sa >> sb;
    int la=sa.size(), lb=sb.size();

    for ( int i=0; i<=la; i++ )
    	ta[i] = 0;
    	
    for ( int i=0; i<=lb; i++ )
    	tb[i] = 0;
    	
    for ( int i=1; i<=la; i++ )
    {
        ta[i] = sa[i-1];
        if ( ta[i] == 'A' )
        	tra[i] = 'T';
        else if ( ta[i] == 'T' )
     		tra[i] = 'A';
     	else if ( ta[i] == 'G' )
     		tra[i] = 'C';
     	else if ( ta[i] == 'C' )
     		tra[i] = 'G';
    }
    for ( int i=1; i<=lb; i++ )
    {
        tb[i] = sb[i-1];
 		if ( tb[i] == 'A' )
        	trb[i] = 'T';
        else if ( tb[i] == 'T' )
     		trb[i] = 'A';
     	else if ( tb[i] == 'G' )
     		trb[i] = 'C';
     	else if ( tb[i] == 'C' )
     		trb[i] = 'G';   
    }
    
	int ans = max(lcs_(la, lb, ta, tb), lcs_(la, lb, ta, trb))*2;
    int mom=la+lb;
    int g=__gcd(ans, mom);
    if ( ans == 0 )
        cout << 0 << '/' << mom << endl;
    else
        cout << ans/g << '/' << mom/g << endl;
    
    return 0;
}
