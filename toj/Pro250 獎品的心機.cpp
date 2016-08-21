#include<stdio.h>
using namespace std;
int sdt[1000100][1100];
int main()
{
	int n, q, a, b, c;
	scanf("%d\n%d",&n &q);
	while( q-- )
	{
		scanf("%d",&a);
		if ( a == 1 )
		{
			scanf("%d %d",&b &c);
			sdt[b-1] += c;
		}
		else
		{
			scanf("%d",%b);
		}
	}
	return 0;
}

