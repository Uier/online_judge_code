#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	long long a, b, x, y, z, p;
    while ( cin >> a >> b >> x >> y ) {
    	z = __gcd(x,y);	x /= z;	y /= z;
    	(x > a||y > b) ? (p=0) : (p=min(a/x,b/y));
    	cout << p*x << ' ' << p*y << '\n';
    }
    return 0;
}
