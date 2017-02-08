#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s, t;
	getline(cin,s);
	getline(cin,t);
	if ( s == t )   cout << -1 << '\n';
	else cout << max(s.size(),t.size()) << '\n';
	return 0;
}

