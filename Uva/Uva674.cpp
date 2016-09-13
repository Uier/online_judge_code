#include <iostream>
#include <string.h>
using namespace std;
long long cg[5]={1, 5, 10, 25, 50}, a[10005];
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int n;
	while ( cin >> n ) {
		memset(a,0,sizeof(a));
		a[0] = 1;
		for ( int i=0; i<5; i++ ) {
			for ( int j=cg[i]; j<=n; j++ )
				a[j] += a[j-cg[i]];
		}
		cout << a[n] << '\n';
	}
	return 0;
}

