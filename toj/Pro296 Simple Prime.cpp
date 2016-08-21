#include <iostream>
using namespace std;
#define maxn 3165
bool np[maxn];
int prime[1000000];
int main()
{
	int x=1, n;
	np[0] = np[1] = true;
	for ( int i=2; i<maxn; i++ )
	{
		if ( !np[i] )
		{
			prime[x++] = i;
			for ( long long j=i*i; j<maxn; j+=i ) 
				np[j] = true;
		}
	}
	while ( cin >> n )
	{
		if ( n >= 3165 )
		{
			for ( int i=3165; i<=n; i++ )
			{
				int flag=0;
				for ( int j=1; prime[j]*prime[j]<n; j++ )
				{
					if ( n%prime[j] == 0 )
					{
						flag = -1;
						break;
					}
				}
				if ( flag != -1 )
			
		}
	}
	return 0;
}
// sqrt(10000000) = 3162. ***;
