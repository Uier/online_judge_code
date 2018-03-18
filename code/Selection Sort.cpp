#include <iostream>
using namespace std;
int a[1005], b[1005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	while ( cin >> n ) {
		int cnt = 0;
		for ( int i=0; i<n; ++i )
			cin >> a[i];
		for ( int i=0; i<n; ++i ) {
			pair<int,int> mini = {2147483647,0};
			for ( int j=0; j<n; ++j )
				if ( a[j] <= mini.first ) {
					mini.second = j;
					mini.first = a[j];
				}
			b[cnt++] = mini.first;
			a[mini.second] = 2147483647;
		}
		for ( int i=0; i<cnt-1; ++i )
			cout << b[i] << ' ';
		cout << b[cnt-1] << '\n';
	}
	return 0;
}

