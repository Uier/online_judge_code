#include <iostream>
#include <set>
using namespace std;
int n;
multiset<int> S;
void work(int x) {
	cout << x << ' ';
	S.erase(S.find(x));
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while ( cin >> n && n ) {
		if ( n > 0 )	S.insert(n);
		else if ( n == -1 && !S.empty() )	work(*S.begin());
		else if ( n == -2 && !S.empty() )	work(*S.rbegin());
	}
	cout << '\n';
	return 0;
}