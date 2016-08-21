#include <stdio.h>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
	int x, y;
	while ( scanf("%d %d", &x, &y) != EOF )
	{
		if ( x == 0 && y == 0 )
			break;
		int gcd=__gcd(x,y), i=2;
		if ( gcd == 1 )
			printf("-1\n");
		else
		{
			while ( i <= gcd )
			{
				if ( gcd%i == 0 )
					gcd /= i;
				else
					i++;
			}
			printf("%d\n", (y-x)/i);
		}
	}
	return 0;
}