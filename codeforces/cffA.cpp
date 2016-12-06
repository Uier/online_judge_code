#include <iostream>
#include <math.h>
using namespace std;
int a[200];
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int n;
	cin >> n;
	for ( int i=0; i<n; i++ )
		cin >> a[i];
	if ( a[n-1] == 15 )
		puts("DOWN");
	else if ( a[n-1] == 0 )
		puts("UP");
	else if ( n == 1 )
		puts("-1");
	else if ( a[n-2] > a[n-1] )
		puts("DOWN");
	else if ( a[n-2] < a[n-1] )
		puts("UP");
	return 0;
}

