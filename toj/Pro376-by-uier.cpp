#include <iostream>
using namespace std;
long long M[2][2], B[2][2], T[2][2], mod = 1000000009;
void BxM() {
	for ( int i=0; i<2; ++i )
		for ( int j=0; j<2; ++j ) {
			long long tmp = 0;
			for ( int k=0; k<2; ++k ) {
				tmp += (B[i][k]*M[k][j])%mod;
				tmp %= mod;
			}
			T[i][j] = tmp;
		}
	for ( int i=0; i<2; ++i )
		for ( int j=0; j<2; ++j )
			B[i][j] = T[i][j];
}
void MxM() {
	for ( int i=0; i<2; ++i )
		for ( int j=0; j<2; ++j ) {
			long long tmp = 0;
			for ( int k=0; k<2; ++k ) {
				tmp += (M[i][k]*M[k][j])%mod;
				tmp %= mod;
			}
			T[i][j] = tmp;
		}
	for ( int i=0; i<2; ++i )
		for ( int j=0; j<2; ++j )
			M[i][j] = T[i][j];
}
long long POW(long long n) {
	M[0][0] = B[0][0] = 1;	M[0][1] = B[0][1] = 1;	//initiation
	M[1][0] = B[1][0] = 1;	M[1][1] = B[1][1] = 0;
	while ( n ) {
		if ( n%2 )	BxM();
		MxM();
		n /= 2;
	}
	return B[1][0];
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n;
	while ( cin >> n )
		cout << POW(n+1)-1 << '\n';
	return 0;
}

