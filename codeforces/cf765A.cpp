#include <iostream>
#include <map>
using namespace std;
map<string,int> M;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m=3;
	cin >> n;
	string s = "";
	M.clear();
	for ( int i=0; i<m; i++ ) {
		char a;
		cin >> a;
		s.push_back(a);
	}
	for ( int i=0; i<n; i++ ) {
		string t = "", r = "";
		for ( int i=0; i<m; i++ ) {
			char a;
			cin >> a;
			t.push_back(a);
		}
		char c;	cin >> c; cin >> c;
		for ( int i=0; i<m; i++ ) {
			char a;
			cin >> a;
			r.push_back(a);
		}
		M[t]++;
		M[r]++;
	}
	if ( M[s]%2 )
		cout << "contest\n";
	else
		cout << "home\n";
	return 0;
}

