#include <stdio.h>
using namespace std;
int main(int argc, char const *argv[]) {
	int n;
	while ( scanf("%d", &n) != EOF ) {
		int i=2, cnt=0, base=0;
		while ( i <= n ) {
			if ( n%i == 0 ) {
				cnt++;
				base = i;
				n /= i;
			}
			else {
				if ( cnt > 1 )
					printf("%d^%d * ", base, cnt);
				if ( cnt == 1 )
					printf("%d * ", base);
				cnt = 0;
				i++;
			}
		}
		if ( cnt > 1 )
			printf("%d^%d\n", base, cnt);
		if ( cnt == 1 )
			printf("%d\n", base);
	}
	return 0;
}
