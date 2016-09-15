#include <iostream>
using namespace std;
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for ( int i=1; i<=m; i++ ) {
		for ( int j=1; j<=n; j++ )
			printf("%d*%d=%d ", i, j, i*j);
		printf("\n");
	}
	return 0;
}

