#include <stdio.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n, a[110];
	for ( int i=0; i<110; i++ )
		a[i] = 0;
	char c;
	scanf("%d %c", &n, &c);
	for ( int i=0; i<n-1; i++ )
	{
		scanf("%d", &a[i]);
		printf("%d%c", a[i], c);
	}
	scanf("%d", &n);
	printf("%d\n", n);
	return 0;
}