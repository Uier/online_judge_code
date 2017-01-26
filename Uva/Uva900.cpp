#include <iostream>
using namespace std;
long long fib[51];
main() {
	fib[0] = fib[1] = 1;
	for ( int i=2; i<51; i++ )
		fib[i] = fib[i-1] + fib[i-2];
	int n;
	while ( scanf("%d", &n) && n )
		printf("%lld\n", fib[n]);
	return 0;
}

