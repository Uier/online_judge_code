#include <iostream>
using namespace std;
char a[55], x;
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	for ( int i=65; i<=90; i++ )
		a[x++] = i;
	for ( int i=97; i<=122; i++ )
		a[x++] = i;
	int n;
	bool first = true;
	while ( scanf("%d", &n) != EOF ) {
		if ( !first )	
			printf("\n");
		first = false;
		printf("%d %d %d\n", 2, n, n);
		for ( int i=0; i<n; i++ ) {
			for ( int j=0; j<n; j++ )
				printf("%c", a[j]);
			printf("\n");
		}
		printf("\n");
		for ( int i=0; i<n; i++ ) {
			for ( int j=0; j<n; j++ )
				printf("%c", a[i]);
			printf("\n");
		}
	}
	return 0;
}

