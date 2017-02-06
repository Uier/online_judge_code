#include <iostream>
#include <stack>
using namespace std;
int in[1010];
stack<int> r;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	while ( cin >> n ) {
		if ( n == 0 )
			break;
		while ( cin >> in[0] ) {
			if ( in[0] == 0 )
				break;
			for ( int i=1; i<n; i++ )
				cin >> in[i];
			int j=0, k=1;
			while ( (j < n) && (k <= n) ) {
				bool f=0;
				if ( in[j] == k ) {
					j++;
					if ( k < n )
						k++;
					f=1;
				}
				else if ( !r.empty() ) {
					if ( in[j] == r.top() ) {
						r.pop();
						j++;
						f=1;
					}
				}
				if ( f == 0 ) {
					r.push(k);
					k++;
				}
			}
			if ( r.empty() )
				cout << "yes" << '\n';
			else {
				cout << "no" << '\n';
				while ( !r.empty() )
					r.pop();
			}
		}
	}
	return 0;
}

