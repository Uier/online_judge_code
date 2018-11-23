#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, arr[25];
	while ( cin >> n ) {
		for ( int i=0; i<n; ++i )
			cin >> arr[i];
		sort(arr,arr+n);
		int highest_fail = -1, lowest_pass = -1;
		for ( int i=0; i<n; ++i ) {
			if ( arr[i] < 60 ) { // fail
				if ( highest_fail == -1 || arr[i] > highest_fail )
					highest_fail = arr[i];
			} else { // pass
				if ( lowest_pass == -1 || arr[i] < lowest_pass )
					lowest_pass = arr[i]; 
			}
		}
		cout << arr[0];
		for ( int i=1; i<n; ++i )
			cout << ' ' << arr[i];
		cout << '\n';
		if ( highest_fail == -1 )	cout << "best case\n";
		else	cout << highest_fail << '\n';
		if ( lowest_pass == -1 )	cout << "worst case\n";
		else	cout << lowest_pass << '\n';
	}
	return 0;
}

