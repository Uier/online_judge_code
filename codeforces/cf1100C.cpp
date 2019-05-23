#include <iostream>
#include <math.h>
#define PI 3.14159265358979323846
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	double n, R;
	cin >> n >> R;
	double a = sin(PI/(n));
	printf("%.10lf\n", (R*a)/(1-a));
	return 0;
}

