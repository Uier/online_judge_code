#include <iostream>
using namespace std;
int a[1005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	while ( cin >> n ) {
		for ( int i=0; i<n; ++i )
			cin >> a[i];
		for ( int i=1; i<n; ++i )
			for ( int j=i; j>0; --j )
				if ( a[j] < a[j-1] )
					swap(a[j],a[j-1]);
		for ( int i=0; i<n-1; ++i )
			cout << a[i] << ' ';
		cout << a[n-1] << '\n';
	}
	return 0;
}

