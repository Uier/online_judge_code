#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n, m, x, d, sum = 0;
	cin >> n >> m;
	long long tmp = n>>1;
	while ( m-- && cin >> x >> d ) {
		sum += x*n;
		if ( n&1 ) {
			sum += max((((n-1)*n)/2)*d,((tmp)*(tmp+1))*d);
		} else {
			sum += max((((n-1)*n)/2)*d,n*n*d/4);
		}		
	}
	printf("%.15lf\n", (double)sum/(double)n);
	return 0;
}

