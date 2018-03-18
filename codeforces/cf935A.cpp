#include <iostream>
#include <math.h>
using namespace std;
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int n;
	long long ans = 0;
	cin >> n;
	for ( int i=2; i<n; ++i )
		if ( (n-i)%i == 0 )	ans++;
	cout << ans+1 << '\n';
	return 0;
}

