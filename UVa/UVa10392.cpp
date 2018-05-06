#include <iostream>
#include <vector>
#define maxp 1000001
using namespace std;
typedef long long ll;
vector<ll> prm;
bool npr[maxp];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	npr[0] = npr[1] = true;
	for ( int i=2; i<maxp; ++i )
		if ( !npr[i] ) {
			prm.emplace_back(i);
			for ( int j=i+i; j<maxp; j+=i )
				npr[j] = true;
		}
	ll n;
	while ( cin >> n && n > 0 ) {
		for ( int i=0; i<prm.size()&&prm[i]*prm[i]<=n; ++i ) {
			while ( n%prm[i] == 0 ) {
				cout << "    " << prm[i] << '\n';
				n /= prm[i];
			}
		}
		if ( n != 1 ) 	cout << "    " << n << '\n';
		cout << '\n';
	}
	return 0;
}

