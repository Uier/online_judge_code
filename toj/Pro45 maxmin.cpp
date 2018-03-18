#include <iostream>
#include <set>
using namespace std;
multiset<int> s;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int H, n, x;
	cin >> H;
	while ( H-- && cin >> n ) {
		while ( n-- && cin >> x )
			s.insert(x);
		cout << (*s.rbegin()-*s.begin()) << '\n';
		s.erase(s.begin());
		auto i = s.end();	i--;
		s.erase(i);
	}
	return 0;
}

