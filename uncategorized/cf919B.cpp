#include <iostream>
#include <vector>
using namespace std;
inline int dgt(int i) {
	int cnt = 0;
	for ( ; i; cnt+=i%10, i/=10 );
	return cnt;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int k, i;
	cin >> k;
	for ( i=19; k; ++i )
		if ( dgt(i) == 10 )	k--;
	cout << i-1 << '\n';
	return 0;
}

