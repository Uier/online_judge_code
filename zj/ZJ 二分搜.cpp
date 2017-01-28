#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n, k;
	while ( cin >> n >> k )
	{
		int na[n];
		for ( int i=0; i<n; i++ )
			cin >> na[i]; 
		sort(na,na+n);
		int a=0, z=n-1, mid=0, ka, ans[k];
		bool y=0;
		for ( int i=0; i<k; i++ )
		{
			cin >> ka;
			y=0;
			mid = 0;
			a = 0;
			z = n - 1;
			while ( a <= z )
			{
				mid = (a+z) / 2;
				if ( ka < na[mid] )
					z = mid-1;
				else if ( ka > na[mid] )
					a = mid+1;
				else
				{
					y = 1;
					ans[i] = mid+1;
					break;
				}
			}
			if ( y == 0 )
				ans[i] = 0;
		}
		for ( int i=0; i<k; i++ )
			cout << ans[i] << endl;
	}
	return 0;	
}
