#include <iostream>
using namespace std;
#define maxn 1000000
bool np[maxn];
int prime[maxn],c=0,num=0;
int main()
{
	for ( int i=0; i<maxn; i++ )
		np[i] = false;
	np[0] = np[1] = true;
	for ( int i=2; i<maxn; i++ )
	{
		if ( !np[i] )
		{
			prime[c] = i;
			c++;
			for ( int j=i+i; j<maxn; j+=i ) 
				np[j] = true;
		}
	}
//	
//	for ( int i=0; i<c; i++ )
//		cout << prime[i] << ' ';
	int q;
	while ( cin >> q )
	{
		if ( np[q] == 1 )
			cout << "isn't prime" << endl;
		else
			cout << "is prime" << endl;
	}
	return 0;
}

