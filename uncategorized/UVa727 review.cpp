#include <iostream>
#include <vector>
using namespace std;
vector<char> tmp;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, f = 0;
	string s;
	cin >> t;
	getline(cin,s);
	getline(cin,s);
	while ( t-- ) {
		if ( f )	cout << '\n';
		else	f = 1;
		tmp.clear();
		while ( getline(cin,s) && s != "" ) {
			char c = s[0];
			if ( c == '(' )	tmp.emplace_back(c);
			else if ( c >= '0' && c <= '9' )	cout << c;
			else if ( c == ')' ) {
				while ( !tmp.empty() && tmp.back() != '(' ) {
					cout << tmp.back();
					tmp.pop_back();
				}
				if ( tmp.back() == '(' )	tmp.pop_back();
			}
			else if ( c == '*' || c == '/' ) {
				while ( !tmp.empty() && (tmp.back() == '*' || tmp.back() == '/') ) {
					cout << tmp.back();
					tmp.pop_back();
				}
				tmp.emplace_back(c);
			} else {
				while ( !tmp.empty() && (tmp.back() == '*' || tmp.back() == '/' || tmp.back() == '+' || tmp.back() == '-') ) {
					cout << tmp.back();
					tmp.pop_back();
				}
				tmp.emplace_back(c);
			}
		}
		while ( !tmp.empty() ) {
			cout << tmp.back();
			tmp.pop_back();
		}
		cout << '\n';
	}
	return 0;
}

