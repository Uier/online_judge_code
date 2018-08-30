#include <iostream>
#define maxn 1005
using namespace std;
double a[maxn<<1];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	cin >> a[0];
	for ( int i=1; i<n; ++i )	cin >> a[i<<1];
	cin >> a[(n<<1)-1];
	for ( int i=1; i<n; ++i )	cin >> a[(i<<1)-1];
	double w = m;
	for ( int i=(n<<1)-1; i>=0; --i ) {
		if ( a[i] == 1 ) {return cout << -1 << '\n', 0;}
		w += w / (a[i]-1);
	}
	printf("%.15lf\n", w-m);
	return 0;
}

