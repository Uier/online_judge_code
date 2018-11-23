#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	double rate = -1, a, b;
	cin >> n >> m;
	while ( n-- && cin >> a >> b )
		if ( rate == -1 || rate > a/b )
			rate = a/b;
	printf("%.10lf\n", m*rate);
	return 0;
}

