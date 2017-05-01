#include<iostream>
using namespace std;
int main() {
	int n;
	while ( cin >> n && n ) {
		int x;
		for ( int i=0; i<n; ++i )
			cin >> x;
		for ( int i=1; i<n; ++i )
			cout << i << ' ';
		cout << n << '\n';
	}
	return 0;
}

