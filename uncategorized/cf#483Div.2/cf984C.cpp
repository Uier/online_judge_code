#include <iostream>
#include <math.h>
#define int long long
#define double long double
using namespace std;
//const double eps = 1e-18;
int dp[20];
main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, p, q, b;
//	double p, q, b;
	cin >> n;
	while ( n-- && cin >> p >> q >> b ) {
		__int128 frac = p;
		bool inf = true;
		for ( int i=0; i<20; ++i ) {
			frac %= p;
			frac *= 10;
			dp[i] = frac/q;
		}
		for ( int i=19; i>=0; --i ) {
			dp[i] = 
		}
		if ( inf )	cout << "Infinite\n";
		else	cout << "Finite\n";
//		double frac = p/q;
//		frac -= (int)frac;
//		double mult = frac;
//		bool infinite = true;
//		for ( int i=0; i<1000&&infinite; ++i ) {
//			mult *= b;
//			mult -= (int)mult;
////			printf("mult: %.15lf\n", mult);
//			if ( mult <= eps )	infinite = false;
//			if ( mult-frac > 0 && mult-frac <= eps )	mult = frac;
//			if ( frac-mult > 0 && frac-mult <= eps )	mult = frac;
//		}
//		if ( infinite )	cout << "Infinite\n";
//		else	cout << "Finite\n";
	}
	return 0;
}

