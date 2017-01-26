#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	int t,n;
	while (cin >> t)
	{
		long long m=1;
		for ( int i=0; i<t; i++ )
		{
			cin >> n;
			m = 1;
			for ( int j=1; j<=n; j++ )
				m = m * j;
			cout << m << endl;
		}
	}
	return 0;
}
