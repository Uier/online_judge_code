#include <iostream>
#define max 46341
bool notp[max];
int prime[max], c=0;
using namespace std;
int main()
{
	int x;
	for ( int i=0; i<max; i++ )
		notp[i] = 0;
	notp[0]=notp[1]=1;
	for ( int i=2; i<max; i++ )
	{
		if ( notp[i] == false )
		{
			prime[c] = i;
			c++;
			for ( int j=i*i; j<max; j+=i )
				notp[j] = 1;
		}
	}
	while ( cin >> x )
	{
		if ( x > max )
		{
			for ( int i=0; i<max; i++ )
			{
				if ( x % prime[i] == 0 )
				{
					cout << "獶借计" << endl;
					break; 
				}
				else if ( i == c-1 )
					cout << "借计" << endl;			
			}
		}
		else
			for ( int i=0; i<x; i++ )
			{
				if ( x % prime[i] == 0 )
				{
					cout << "獶借计" << endl;
					break; 
				}
				else if ( i == c-1 )
					cout << "借计" << endl;			
			}
	}
//	for ( int i=0; i<c; i++ )
//		cout << prime[i] << ' ';
	return 0;
}
