#include <iostream>
#include <math.h>
using namespace std;
typedef pair<int,int> pii;
struct ln {
	int xa, ya, xb, yb;
} dot[5];
int det(pii fir, pii sec) {
	return fir.first*sec.second-fir.second*sec.first;
}
bool intersection(ln fir, ln sec) {
	int a = det(pii{(fir.xb-fir.xa),(fir.yb-fir.ya)},pii{(sec.xa-fir.xa),(sec.ya-fir.ya)});
	int b = det(pii{(fir.xb-fir.xa),(fir.yb-fir.ya)},pii{(sec.xb-fir.xa),(sec.yb-fir.ya)});
	int c = det(pii{(sec.xb-sec.xa),(sec.yb-sec.ya)},pii{(fir.xa-sec.xa),(fir.ya-sec.ya)});
	int d = det(pii{(sec.xb-sec.xa),(sec.yb-sec.ya)},pii{(fir.xb-sec.xa),(fir.yb-sec.ya)});
	if ( a*b < 0 && c*d < 0 )	return true;
	if ( a*b > 0 || c*d > 0 )	return false;
	if ( a == 0 && min(fir.xa,fir.xb) <= sec.xa && sec.xa <= max(fir.xa,fir.xb)
				&& min(fir.ya,fir.yb) <= sec.ya && sec.ya <= max(fir.ya,fir.yb) )	return true;
	if ( b == 0 && min(fir.xa,fir.xb) <= sec.xb && sec.xb <= max(fir.xa,fir.xb)
				&& min(fir.ya,fir.yb) <= sec.yb && sec.yb <= max(fir.ya,fir.yb) )	return true;
	if ( c == 0 && min(sec.xa,sec.xb) <= fir.xa && fir.xa <= max(sec.xa,sec.xb)
				&& min(sec.ya,sec.yb) <= fir.ya && fir.ya <= max(sec.ya,sec.yb) )	return true;
	if ( d == 0 && min(sec.xa,sec.xb) <= fir.xb && fir.xb <= max(sec.xa,sec.xb)
				&& min(sec.ya,sec.yb) <= fir.yb && fir.yb <= max(sec.ya,sec.yb) )	return true;
	return false;
}
main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, a, b, c, d;
	cin >> n;
	while ( n-- ) {
		cin >> dot[0].xa >> dot[0].ya >> dot[0].xb >> dot[0].yb;
		cin >> a >> b >> c >> d;
		if ( a > c )	swap(a,c);
		if ( b < d )	swap(b,d);
		// line in the rec
		if ( a <= min(dot[0].xa,dot[0].xb) && max(dot[0].xa,dot[0].xb) <= c &&
			 d <= min(dot[0].ya,dot[0].yb) && max(dot[0].ya,dot[0].yb) <= b ) {
			cout << "T\n";
			continue; 	
		}
		dot[1] = ln{a,b,c,b}; // top
		dot[2] = ln{c,b,c,d}; // right
		dot[3] = ln{c,d,a,d}; // bottom
		dot[4] = ln{a,d,a,b}; // left
		bool flag = true; // fail
		for ( int i=1; i<5; ++i ) {
			if ( intersection(dot[0],dot[i]) ) {
				cout << "T\n";
				flag = false;
				break;
			}
		}
		if ( flag )	cout << "F\n";
	}
	return 0;
}

