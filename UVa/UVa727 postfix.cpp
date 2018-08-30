#include <iostream>
#include <vector>
using namespace std;
vector<char> V, S; 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	bool first = 1;
	string s;
	cin >> t;
	getline(cin,s);
	getline(cin,s);
	while ( t-- ) {
		if ( !first )	cout << '\n';
		first = 0;
		V.clear();
		S.clear();
		while ( getline(cin,s) && s != "" )
			V.emplace_back(s[0]);
		for ( char i : V )
			if ( i == '(' ) {
				S.push_back(i);
			} else if ( i == ')' ) {
				while ( S.back() != '(' ) {
					cout << S.back();
					S.pop_back();
				}
				S.pop_back();
			} else if ( i == '*' || i == '/' ) {
				while ( S.size() && (S.back() == '*' || S.back() == '/') ) {
					cout << S.back();
					S.pop_back();
				}
				S.emplace_back(i);
			} else if ( i == '+' || i == '-' ) {
				while ( S.size() && (S.back() == '*' || S.back() == '/' || S.back() == '+' || S.back() == '-') ) {
					cout << S.back();
					S.pop_back();
				}
				S.emplace_back(i);
			} else	cout << i;
		for ( int i=S.size()-1; i>=0; --i )	cout << S[i];
		cout << '\n';
	}
	return 0;
}

