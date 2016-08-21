#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
using namespace std;
int pi[60];
int main(int argc, char const *argv[])
{
	double n;
	while ( cin >> n )
	{
		if ( n == 0 )
			break;
		int ep=0;
		double m=n*(n-1)/2;
		for ( int i=0; i<n; i++ )
			pi[i] = 0;
		for ( int i=0; i<n; i++ )
		{
			cin >> pi[i];
			if ( i )
				for ( int j=0; j<i; j++ )
					if ( __gcd(pi[i],pi[j]) == 1 )
						ep++;
		}
		if ( ep == 0 )
			cout << "No estimate for this data set.\n";
		else
		{
			double ans=6/(ep/m);
			printf("%.6lf\n", sqrt(ans));
		}
	}
	return 0;
}