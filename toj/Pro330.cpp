#include <stdio.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	long long x=a+c, y=b+d;
	printf("%lld %lld\n", x, y);
	return 0;
}