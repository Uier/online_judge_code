#include <iostream>
#include <map>
using namespace std;
map<string,string> M;
inline bool Naeiou(char x) {
	if ( x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' )	return 0;
	return 1;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int l, n;
	string s, t;
	cin >> l >> n;
	while ( l-- && cin >> s >> t )	M[s] = t;
	while ( n-- && cin >> s ) {
		int len = s.size();
		if ( M[s] != "" )	cout << M[s] << '\n';
		else if ( s.back() == 'y' && len > 1 && Naeiou(s[len-2]) ) {
			s.pop_back();
			cout << s << "ies\n";
		} else if ( s.back() == 'o' || s.back() == 's' || s.back() == 'x' || (s.back() == 'h' && (len > 1 && s[len-2] == 's' || s[len-2] == 'c')) )
			cout << s << "es\n";
		else	cout << s << "s\n";
	}
	return 0;
}

