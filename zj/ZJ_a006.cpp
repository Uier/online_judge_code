#include <stdio.h>
#include <math.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int a, b, c;
	while ( scanf("%d %d %d", &a, &b, &c) != EOF )
	{
		int D=b*b-4*a*c;
		if ( D < 0 )
			printf("No real root\n");
		else if ( D == 0 )
			printf("Two same roots x=%d\n", -b/(2*a));
		else
			printf("Two different roots x1=%.0f , x2=%.0f\n", (sqrt(D)-b)/(2*a), (-(b+sqrt(D)))/(2*a));
	}
	return 0;
}