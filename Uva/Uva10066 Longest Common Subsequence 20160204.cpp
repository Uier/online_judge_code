#include<iostream>
using namespace std;
int t1[1000]={0}, t2[1000]={0};
int lcs[1000][1000];
int main()
{
	int n1, n2, z=0;
	while( cin >> n1 >> n2 )
	{
		int g=0;
		z++;
		lcs[0][0] = 0;
		if ( (n1 == 0) && (n2 == 0) )
			break;
		for ( int i=1; i<=n1; i++ )
		{ 
			cin >> t1[i];
			lcs[0][i] = 0;
		}
		for ( int i=1; i<=n2; i++ )
		{
			cin >> t2[i];
			lcs[i][0] = 0;
		}
		for ( int i=1; i<=n1; i++ )
		{
			for ( int j=1; j<=n2; j++ )
			{
				if ( lcs[i-1][j] >= lcs[i][j-1] )
				{
					if ( t1[i] == t2[j] )
						lcs[i][j] = lcs[i-1][j-1]+1; //??
					else
						lcs[i][j] = lcs[i-1][j];
				}
				else
				{
					if ( t1[i] == t2[j] )
						lcs[i][j] = lcs[i-1][j-1]+1; //??
					else
						lcs[i][j] = lcs[i][j-1];
				}
			}
		}
		cout << "Twin Towers #" << z << endl;
		cout << "Number of Tiles : " << lcs[n1][n2] << endl;
	}
	return 0;
}

