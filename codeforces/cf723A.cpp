#include <iostream>
#include <math.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, b, c;
	cin >> a >> b >> c;
	if ( a > b )	swap(a,b);
	if ( b > c )	swap(b,c);
	if ( a > b )	swap(a,b);
	int ans=1000;
	for ( int i=a; i<=c; i++ )
		ans = min(ans,(abs(i-a)+abs(i-b)+abs(i-c)));
	cout << ans << '\n';
	return 0;
}

