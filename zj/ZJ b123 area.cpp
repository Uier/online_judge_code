#include<iostream>
using namespace std;
int main()
{
	int m, n, x;
	cin >> m >> n;
	int dp[m+1][n+1];
	for ( int i=1; i<m; i++ )
	{
		for ( int j=1; j<n; j++ )
		{
			cin >> dp[i][j];
			if ( dp[i][j-1] )
		}
	}
	return 0;
}

