#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t, n, k;
	cin >> t;
	while ( t-- && cin >> n >> k ) {
		string s = "";
		for ( int i=0, j=0; i<n; ++i, ++j ) {
			j %= k;
			s.push_back(char('a'+j));
		}
		cout << s << '\n';
	}
	return 0;
}

