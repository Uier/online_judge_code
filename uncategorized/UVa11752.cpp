#include <iostream>
#include <vector>
#include <set>
#define int unsigned long long
using namespace std;
vector<int> arr;
set<int> S;
__int128 _pow(__int128 a, __int128 b) {
	__int128 ans = 1;
	while ( b ) {
		if ( b&1 )	ans *= a;
		a *= a;
		b >>= 1;
	}
	return ans;
}
main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	S.insert(1);
	for ( int i=4; i<=64; ++i ) {
		bool f = 1;
		for ( int j=2; j<i; ++j )
			if ( i%j == 0 )	f = 0;
		if ( f == 0 )	arr.emplace_back(i);
	}
	int pt = 2;
	__int128 inf = 1;
	for ( int i=0; i<64; ++i )	inf *= 2;
	while ( true ) {
		bool used = 0;
		int i = 0;
		__int128 tmp = _pow(pt,arr[i++]);
		while ( tmp < inf ) {
			S.insert(tmp);
			tmp = _pow(pt,arr[i++]);
			used = true;
		}
		if ( !used )	break;
		pt++;
	}
	for ( auto i=S.begin(); i!=S.end(); ++i )
		cout << *i << '\n';
	return 0;
}

