#include <iostream>
#include <vector>
using namespace std;
int nod[65000], T, N, C = 1;
bool npr[1000005];
vector<int> prm;
int solve(int x) {
	int y = 0, fac = 1;
	while ( x != 1 ) {
		int tmp = 0;
		while ( x%prm[y] == 0 ) {
			tmp++;
			x /= prm[y];
		}
		fac *= tmp+1;
		y++;
	}
	return fac;
}
main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	npr[0] = npr[1] = true;
	for ( int i=2; i<=1000000; ++i ) {
		if ( !npr[i] ) {
			prm.push_back(i);
			for ( int j=i+i; j<=1000000; j+=i )
				npr[j] = true;
		}
	}
	nod[0] = 1;
	for ( N = 1; nod[N-1]<1000000; ++N )
		nod[N] = nod[N-1] + solve(nod[N-1]);
	cin >> T;
	while ( T-- ) {
		int a, b, c = 0, d = 0;
		cin >> a >> b;
		c = lower_bound(nod,nod+N,a)-nod;
		auto x = lower_bound(nod,nod+N,b);
		d = ((*x == b) ? x-nod+1: x-nod );
		cout << "Case " << C++ << ": " << d-c << '\n';
	}
	return 0;
}

