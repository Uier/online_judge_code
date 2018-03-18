#include <iostream>
using namespace std;
int main() {
	int n, a[1000];
	scanf("%d", &n);
	for ( int i=0; i<n; ++i )	cin >> a[i];
	for ( int i=0; i<n; ++i ) {
		int tau = 0;
		for ( int j=0; j<n; ++j )
			tau += (j-i)*a[j];
		if ( tau == 0 )	{
			printf("%d\n", i+1);
			break;
		}
		if ( tau < 0 ) {
			printf("%d %d\n", i, i+1);
			break;
		}
	}
	return 0;
}

