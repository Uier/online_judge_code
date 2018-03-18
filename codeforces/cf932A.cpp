#include <iostream>
using namespace std;
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	string s, t = "";
	cin >> s;
	for ( int i=0; i<s.size(); ++i )
		t.push_back(s[s.size()-1-i]);
	cout << s << t << '\n';
	return 0;
}

