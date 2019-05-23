#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
vector<int> arr;
main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int sum = (n+1)*n/2;
	for ( int i=1; i*i<=n; ++i )
		if ( n%i == 0 ) {
			int j = n/i;
			arr.emplace_back((sum-j*(j-1)/2*i)/j);
			if ( i!= j ) arr.emplace_back((sum-i*(i-1)/2*j)/i);
		}
	sort(arr.begin(),arr.end());
	for ( int i : arr )	cout << i << ' ';
	return 0;
}

