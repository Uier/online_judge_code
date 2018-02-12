#include <iostream>
using namespace std;
typedef long long ll;
ll QPOW(ll a, ll b, ll c) {
	if ( b == 0 )	return 1;
	if ( b == 1 )	return a;
	if ( b&1 )	return (a*QPOW(a,b-1,c))%c;
	ll tmp = QPOW(a,b/2,c);
	return (tmp*tmp)%c;
}
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	ll a, b, c;
	while ( cin >> a >> b >> c )
		cout << QPOW(a,b,c) << '\n';
	return 0;
}

