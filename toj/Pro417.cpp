#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	for ( int i=0; i<s.size(); ++i )
		if ( s[i] != '2' && s[i] != '3' && s[i] != '5' && s[i] != '7' ) {
			cout << "No\n";
			return 0;
		}
	cout << "Yes\n";
	return 0;
}

