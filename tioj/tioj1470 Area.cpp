#include<iostream>
using namespace std;
int main()
{
	int m, n, x, max=0, a=0, b=0;
	cin >> n >> m;
	int dp[n+1][m+1] = {{0}};
	for ( int i=1; i<n+1; i++ )
	{
		for ( int j=1; j<m+1; j++ )
		{
			cin >> x;
			if ( (x > dp[i-1][j]) && (x > dp[i][j-1]) )
			{
				if ( dp[i-1][j] > dp[i][j-1] )
					
				else
					 
			}
			else
				dp[i][j] = 0;
			if ( dp[i][j] > max )
			{
				a = i;
				b = j;
			}	
		}
	}
	for ( int i=a; i>0; i-- )
	{
		for ( int j=b; j>0; j-- )
		{
			
		}
	}
	
	return 0;
}

