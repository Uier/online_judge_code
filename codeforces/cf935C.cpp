#include <iostream>
#include <math.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	double R, x1, y1, x2, y2;
	cin >> R >> x1 >> y1 >> x2 >> y2;
	double dist = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	double r = (R+dist)/2;
	if ( dist >= R )	cout << x1 << ' ' << y1 << ' ' << R << '\n';
	else if ( dist == 0 )
		printf("%.8lf %.8lf %.8lf\n", x1, y1+r, r);
	else {
		double vx = (x2-x1)/dist, vy = (y2-y1)/dist;
		printf("%.8lf %.8lf %.8lf\n", x2-vx*r, y2-vy*r, r);
	}
	return 0;
}

