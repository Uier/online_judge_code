#include <iostream>
using namespace std;
inline void _x_(int A[][2], int B[][2]) {
	int T[2][2] = {{0,0}, {0,0}}, tmp;
	for ( int i=0; i<2; ++i )
		for ( int j=0; j<2; ++j ) {
			tmp = 0;
			for ( int k=0; k<2; ++k )	tmp = (tmp+A[i][k]*B[k][j])%10000;
			T[i][j] = tmp;
		}
	for ( int i=0; i<2; ++i )
		for ( int j=0; j<2; ++j )
			A[i][j] = T[i][j];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	while ( cin >> n ) {
		int M[2][2] = {{1,0}, {0,1}}, B[2][2] = {{1,1}, {1,0}};
		n--;
		while ( n > 0 ) {
			if ( n&1 )	_x_(M,B);
			_x_(B,B);
			n >>= 1;
		}
		cout << (M[0][0]+M[0][1])%10000 << '\n';
	}
	return 0;
}
