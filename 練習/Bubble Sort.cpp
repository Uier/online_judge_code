#include<iostream>
using namespace std;
int in[50010];
int main()
{
	int n, time=0;
	while ( cin >> n )
	{
		time=0;
		if ( !n )
			break;
		for ( int i=0; i<n; i++ )
			cin >> in[i];
		for ( int i=n; i>0; i-- )
		{
			for ( int j=0; j<i; j++ )
			{
				if ( in[j] > in[j+1] )
				{
					swap(in[j],in[j+1]);
					time++;
				}
			}
		}
		cout << time << endl;
	}
	return 0;
}

