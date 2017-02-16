#include<iostream>
using namespace std;
string s, t;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	while ( n-- ) {
		cin >> s >> t;
		if ( s.size() > t.size() )	cout << 0 << '\n';
		else if ( s.size() < t.size() )	cout << 1 << '\n';
		else
			cout << (t > s) << '\n';
	}
	return 0;
}
