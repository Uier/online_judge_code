#include<iostream>
using namespace std;
int ar[100][100]={{0},{0}};
int od[100][100]={{0},{0}};
int main()
{
	int n, m, er=-300, u=0, d=0;
	while ( cin >> n )
	{
		for ( int i=0; i<n; i++ )
		{
			for ( int j=0; j<n; j++ )
			{
				cin >> m;
				if ( j == 0 )
		        	od[i][j] = m;
		        else
		        	od[i][j] = m + od[i][j-1];
				if ( i == 0 )
				{
					if ( j == 0 )
						ar[i][j] = m;
					else
						ar[i][j] = m + ar[i][j-1];
				}
				else
				{
					if ( j == 0 )
						ar[i][j] = m + ar[i-1][j];
					else
						ar[i][j] = od[i][j] + ar[i-1][j];
				}
				if ( ar[i][j] > er )
				{
					er = ar[i][j];
					u = i;
					d = j;
				}
			}
		}
		for ( int i=u-1; i>=0; i-- )
		{
			if ( ar[i][d] < 0 )
			{
				er -= ar[i][d];
				break;
			}
		}
		cout << er << endl;
	}
	return 0;
}

