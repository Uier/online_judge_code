#include <iostream>
using namespace std;
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	double a, l, i=0;
	cin >> a >> l;
	double R = l*l;
	while ( R > a ) {
		i++;
		R /= 2;	
	}
	cout << i << '\n';
	return 0;
}

