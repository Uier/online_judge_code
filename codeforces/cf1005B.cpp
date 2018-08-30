#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s, t;
	cin >> s >> t;
	while ( s.size() != 0 && t.size() != 0 ) {
		if ( s.back() == t.back() ) {
			s.pop_back();
			t.pop_back();
		} else break;
	}
	cout << s.size()+t.size() << '\n';
	return 0;
}

