#include <iostream>
#include <set>
using namespace std;
set<string> S;
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	string s;
	cin >> s;
	S.clear();
	S.insert(s);
	for ( int i=1; i<s.size(); i++ ) {
		string t = "";
		for ( int j=i; j<s.size(); j++ )
			t.push_back(s[j]);
		for ( int j=0; j<i; j++ )
			t.push_back(s[j]);
		S.insert(t); 
	}
	cout << S.size() << '\n';
	return 0;
}

