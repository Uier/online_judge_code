#include <iostream>
#include <math.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	while ( cin >> s ) {
		int len = s.size();
		for ( int i=1; i<len; ++i )
			cout << abs((int)(s[i]-s[i-1]));
		cout << '\n';
	}
	return 0;
}

