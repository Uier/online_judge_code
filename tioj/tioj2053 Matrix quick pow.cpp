#include <iostream>
using namespace std;
int x1, x2, a, b, n, mod = 1000000007;
long long M[2][2], B[2][2], T[2][2];
void MxM() {
	T[0][0] = T[0][1] = T[1][0] = T[1][1] = 0;
	for ( int i=0; i<2; ++i )
		for ( int j=0; j<2; ++j )
			for ( int k=0; k<2; ++k ) {
				T[i][j] += (M[i][k]*M[k][j])%mod;
				T[i][j] %= mod;
			}
	for ( int i=0; i<2; ++i )
		for ( int j=0; j<2; ++j )
			M[i][j] = T[i][j];
}
void BxM() {
	T[0][0] = T[0][1] = T[1][0] = T[1][1] = 0;
	for ( int i=0; i<2; ++i )
		for ( int j=0; j<2; ++j )
			for ( int k=0; k<2; ++k ) {
				T[i][j] += (B[i][k]*M[k][j])%mod;
				T[i][j] %= mod;
			}
	for ( int i=0; i<2; ++i )
		for ( int j=0; j<2; ++j )
			B[i][j] = T[i][j];
}
void POW(int n) {
	M[0][0] = b;	M[0][1] = a;
	M[1][0] = B[0][0] = B[1][1] = 1;
	while ( n ) {
		if ( n&1 )	BxM();
		MxM();
		n >>= 1;
	}
	cout << ((B[0][0]*x2)%mod+(B[0][1]*x1)%mod)%mod << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> x1 >> x2 >> a >> b >> n;
	POW(n-2);
	return 0;
}

