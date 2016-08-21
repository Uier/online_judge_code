#include<iostream>
using namespace std;
int main()
{
	int n,flag=0;
	string x,y;
	cin >> n >> x >> y;
	for ( int k=0; k<n; k++ )
	{
		if ( (k == 0) && (x[0] == 0) && (y[0] == 0) )
			flag = 1;
		else if ( (k == n-1) && (x[n-1] == 0) && (y[n-1] == 0) )
			flag = 1;
		else 
		{
			if ( x[k] == 0 )
			{
				if ( y[k] == 0 )
					flag = 1;
				if ( y[k+1] == 0 )
					flag = 1;
				if ( y[k-1] == 0 )
					flag = 1;
			}
		}
		if ( flag == 1 ) 
			break;
	}
	if ( flag == 1 ) 
		cout << "FENESTRATION FORTIFICATION FAILURE!" << endl;
	else
		cout << "FENDED OFF!" << endl;
	return 0;
}
