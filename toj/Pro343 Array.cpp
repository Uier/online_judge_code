#include <iostream>
#include <algorithm>
#define maxn 10000005
using namespace std;
int a[maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for ( int i=0; i<n; ++i )	cin >> a[i];
	sort(a,a+n);
	if ( a[0] == a[n-1] )	cout << "Same!\n";
	else	cout << a[n-1] << ' ' << a[0] << '\n';
	return 0;
}

