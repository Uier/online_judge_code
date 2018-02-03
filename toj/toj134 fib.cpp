//#include <iostream>
//using namespace std;
//typedef long long ll;
//ll f[500][110];
//int main() {
////	ios::sync_with_stdio(0);
////	cin.tie(0);
//	f[1][0] = f[2][0] = 1;
//	int n;
//	cin >> n;
//	for ( int i=3; i<=n; ++i ) {
//		int carry = 0;
//		for ( int j=0; j<110; ++j ) {
//			f[i][j] = f[i-1][j] + f[i-2][j] + carry;
//			carry = f[i][j]/10;
//			f[i][j] %= 10;
//		}
//	}
//	int x = 109;
//	while ( f[n][x] == 0 )	x--;
//	for ( int i=x; i>=0; --i )
//		cout << f[n][i];
//	cout << '\n';
//	return 0;
//}
#include <iostream>
using namespace std;
short a[105], b[105];
void PRT(short *c) {
	int x = 104;
	while ( c[x] == 0 )	x--;
	for ( int i=x; i>=0; --i )
		cout << c[i];
	cout << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	a[0] = b[0] = 1;
	int n;
	cin >> n;
	for ( int i=3; i<=n; ++i ) {
		int carry = 0;
		if ( i&1 )
			for ( int j=0; j<105; ++j ) {
				a[j] = a[j] + b[j] + carry;
				carry = a[j]/10;
				a[j] %= 10;
			}
		else
			for ( int j=0; j<105; ++j ) {
				b[j] = a[j] + b[j] + carry;
				carry = b[j]/10;
				b[j] %= 10;
			}
	}
	if ( n&1 )	PRT(a);
	else	PRT(b);
	return 0;
}

