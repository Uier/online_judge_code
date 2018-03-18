#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
vector<ll> prm;
bool is_prm(ll x) {
	for ( int i=0; prm[i]*prm[i]<=x; ++i )
		if ( x%prm[i] == 0 )
			return false;
	return true;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	prm.emplace_back(2);
	prm.emplace_back(3);
	for ( ll i=5, gap=2; i<1e7; i+=gap, gap=6-gap ) {
		if ( is_prm(i) )
			prm.emplace_back(i);
	}
	ll n;
	bool f = false;
	while ( cin >> n && n >= 0 ) {
		if ( f )	cout << '\n';
		f = true;
		int cnt = 0, m = n;
		for ( int i=0; prm[i]*prm[i]<=n; ++i ) {
			if ( n%prm[i] == 0 ) {
				cnt++;
				cout << '\t' << prm[i] << '\n';
				n /= prm[i];
			}
		}
		if ( cnt == 0 )	cout << '\t' << m << '\n';
	}
	return 0;
}

