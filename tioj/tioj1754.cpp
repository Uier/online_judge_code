#include<iostream>
using namespace std;
int main()
{
	int t;
	cin >> t; 
	while ( t-- )
	{
		int n, m, k;
		cin >> n >> m >> k;
		if ( k >= m )
			cout << 0 << endl;
		else
		{
			int i=0, j=1, x=0;
			long long sum=1;
			while ( i < m-1 )
			{
				if ( n-j-x != 0 )
					sum *= n-j-x;
				i++;
				if ( j <= k+1 )
					j++;
				if ( (i > k) && (k+1 < m-i) )	// X ¬°ªÅªº
					x=-1;
			cout << sum%1000000007 << endl;
			}
		}
	}
	return 0;
}

