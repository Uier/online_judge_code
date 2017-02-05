#include<iostream>
using namespace std;

bool ac[200001];
int main()
{
	int m, n, a;
	cin >> m >> n;
	while ( m-- )
	{
		for ( int i=0; i<200001; i++ )
			ac[i] = false;
		ac[100000] = true;
		for ( int f=0; f<n; f++ )
		{
			int x=0, rec[200000];
			cin >> a;
			for ( int i=0; i<200001; i++ )
			{
				if ( ac[i] )
				{
					rec[x++] = i+a;
					rec[x++] = i-a;
					ac[i] = false;
				}
			}
			for ( int i=0; i<x; i++ )
				ac[rec[i]] = true;
		}
		if ( ac[100000] )
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}

