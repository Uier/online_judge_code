#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll a[1000000];
int main(int argc, char const *argv[])
{
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	ll n;
	while ( cin >> n ) {
		for ( int i=0; i<n; i++ )
			cin >> a[i];
		sort(a,a+n);
		for ( int i=0; i<n-1; i++ )
			cout << a[i] << ' ';
		cout << a[n-1] << '\n';
	}
	return 0;
}