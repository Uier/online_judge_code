#include <iostream>
#include <set>
using namespace std;
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int q=0;
	string s;
	cin >> s;
	set<char> S;
	S.clear();
	for ( int i=65; i<=90; i++ )
		S.insert(i);
	for ( int i=0; i<s.size(); i++ ) {
		if ( S.find(s[i]) != S.end() )
			S.erase(s[i]);
		if ( s[i] == '?' )
			q++;
	}
	if ( s.size() < 26 || S.size() > q )
		cout << -1 << '\n';
	else {
		for ( int i=0; i<s.size(); i++ )
			if ( s[i] == '?' ) {
				if ( S.empty() )
					s[i] = 65;
				else {
					char x = *S.begin();
					s[i] = x;
					S.erase(x);
				}
			}
		cout << s << '\n';
	}
	return 0;
}

