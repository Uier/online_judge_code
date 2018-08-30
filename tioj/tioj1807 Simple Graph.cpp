#include <iostream>
#include <map>
using namespace std;
typedef pair<int,int> pii;
map<pii,int> M;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m, n, u, v;
	cin >> m >> n;
	while ( n-- && cin >> u >> v )
		if ( u == v ) {
			cout << "Yes\n";
			return 0;
		}
		else {
			if ( u > v )	swap(u,v);
			if ( M[pii{u,v}]++ ) {
				cout << "Yes\n";
				return 0;
			}
		}
	cout << "yes\n";
	return 0;
}
