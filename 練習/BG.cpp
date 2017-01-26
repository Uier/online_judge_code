#include <iostream>
using namespace std;
int main() {
	int n;
	while ( cin >> n ) {
		int a[n], max=-1000000000, x=0;
		for ( int i=0 ;i<n; i++ ) {
			cin >> a[i];
			if ( a[i] > max ) {
				x = i;
				max = a[i];	
			}
		}
		cout << x+1 << ' ' << a[x] << '\n';
	}
	return 0;
}
