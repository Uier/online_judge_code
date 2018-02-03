#include <iostream>
using namespace std;
int M[2][2], B[2][2], T[2][2];
const int mod = 1000000009;
void MxM() {
	for ( int i=0; i<2; ++i )
		for ( int j=0; j<2; ++j ) {
			int tmp = 0;
			for ( int k=0; k<2; ++k ) {
				tmp += (M[i][k]*M[k][j])%mod;
				tmp = tmp%mod;
			}
			T[i][j] = tmp;
		}
	for ( int i=0; i<2; ++i )
		for ( int j=0; j<2; ++j )
			M[i][j] = T[i][j];
}
void MxD() {
	for ( int i=0; i<2; ++i )
		for ( int j=0; j<2; ++j ) {
			int tmp = 0;
			for ( int k=0; k<2; ++k ) {
				tmp += (M[i][k]*B[k][j])%mod;
				tmp = tmp%mod;
			}
			T[i][j] = tmp;
		}
	for ( int i=0; i<2; ++i )
		for ( int j=0; j<2; ++j )
			M[i][j] = T[i][j];
}
void EXP(int n) {
	if ( n == 1 )	return;
	if ( n%2 )
}
//	cout << "M: " << M[0][0] << ' ' << M[0][1] << ' ' << M[1][0] << ' ' << M[1][1] << '\n';
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int n;
	while ( cin >> n ) {
		M[0][0] = B[0][0] = 1;	M[0][1] = B[0][1] = 1;
		M[1][0] = B[1][0] = 1;	M[1][1] = B[1][1] = 0;
		EXP(n);
		(((2*M[1][0])%mod+M[1][1]-1)%mod);
		cout <<  << '\n';
	}
	return 0;
}

