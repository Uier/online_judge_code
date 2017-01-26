#include <stdio.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	while ( n-- )
	{
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		if ( b-a == c-b )
			printf("%d %d %d %d %d\n", a, b, c, d, d+c-b);
		else
			printf("%d %d %d %d %d\n", a, b, c, d, d*c/b);
	}
	return 0;
}