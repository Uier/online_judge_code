#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <map>
#include <algorithm>
#include <cmath>
#define int long long
using namespace std;
vector<int> divi;
main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a, b, ans = 1e18, k = -1;
	cin >> a >> b;
	if ( a > b )	swap(a,b);
	int d = b-a;
	if ( d == 0 || a == 1 || b%a == 0 || __gcd(a,b) == d || a%d == 0 )
		return cout << 0 << '\n', 0;
	for ( int i=1; i*i<=d; ++i ) {
		if ( d%i == 0 ) {
			divi.emplace_back(i);
			if ( i != d/i )	divi.emplace_back(d/i);
		}
	}
	int sz = divi.size();
	for ( int i : divi ) {
//		cout << "i: " << i << '\n';
		
		if ( i < a )	continue;
		int tmp = i-a;
		int gcd = __gcd(i,b+tmp);
//		cout << "gcd,i,b+tmp: " << gcd << ' ' << i << ' ' << b+tmp << '\n';
//		cout << "i*gcd,b+tmp/gcd: " << i/gcd << ' ' << (b+tmp)/gcd << '\n';
//		cout << "lcm: " << gcd*((i)/gcd)*((b+tmp)/gcd) << '\n';
//		cout << "ans,lcm: " << ans << ' ' << gcd*((i)/gcd)*((b+tmp)/gcd) << '\n';
		if ( gcd*((i)/gcd)*((b+tmp)/gcd) < ans ) {
//			cout << "ans: " << ans << '\n';
			ans = gcd*((a+i)/gcd)*((b+i)/gcd);
			k = tmp;
		}
	}
	if ( k == -1 ) {
		k = ((a/d)+1)*d-a;
	}
	cout << k << '\n';
	return 0;
}

