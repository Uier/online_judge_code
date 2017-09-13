#include <iostream>
using namespace std;
long long n, m, mod[20], M[2][2], B[2][2], T[2][2];
void MxB() {
	for ( int i=0; i<2; ++i )
		for ( int j=0; j<2; ++j ) {
			long long tmp = 0;
			for ( int k=0; k<2; ++k )
				tmp += M[i][k]*B[k][j], tmp %= mod[m];
			T[i][j] = tmp;
		}
	for ( int i=0; i<2; ++i )
		for ( int j=0; j<2; ++j )
			M[i][j] = T[i][j]; 
}
void BxB() {
	for ( int i=0; i<2; ++i )
		for ( int j=0; j<2; ++j ) {
			long long tmp = 0;
			for ( int k=0; k<2; ++k )
				tmp += B[i][k]*B[k][j], tmp %= mod[m];
			T[i][j] = tmp;
		}
	for ( int i=0; i<2; ++i )
		for ( int j=0; j<2; ++j )
			B[i][j] = T[i][j];
}
long long Fib() {
	M[0][0] = M[1][1] = 1;	M[0][1] = M[1][0] = 0;
	B[0][0] = B[0][1] = B[1][0] = 1;	B[1][1] = 0;
	while ( n ) {
		if ( n & 1 )	MxB();
		BxB();
		n >>= 1;
	}
	return M[1][0];
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	mod[0] = 1;
	for ( int i=1; i<20; ++i )	mod[i] = mod[i-1]*2;
	while ( cin >> n >> m )
		cout << Fib() << '\n';
	return 0;
}

