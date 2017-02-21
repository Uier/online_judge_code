#include <iostream>
using namespace std;
int a[100010];
int main()
{
	int n;
	bool x;
	cin >> n;
	for ( int i=0; i<n; i++ )
	{
		int b;
		scanf("%d", &b);
		if ( b%2 == 1 )
			a[i] = 0;
		else
			a[i] = 1;
		if ( i==0 )
			x=a[i];
		else
			x ^= a[i];
		if ( x )
			printf("1\n");
		else
			printf("2\n");
	}
	return 0;
}

