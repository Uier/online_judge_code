#include <iostream>
#include <set>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, r, p=0;
	bool m[10];for ( int i=0; i<10; i++ )	m[i] = false;
	string s;
	set<string> S;
	cin >> n >> r >> s;
	S.clear();
	for ( int i=0; i<s.size(); i++ )
		p += s[i]-'0';
	for ( int i=0; i<=9; i++ ) {
		int q=p+i;
		while ( q > 9 ) {
			int k=0;
			while ( q > 0 ) {
				k += q%10;
				q /= 10;
			}
			q = k;
		}
		if ( q == r )
			m[i] = true;
	}
	for ( int i=0; i<=9; i++ )
		if ( m[i] )
			for ( int j=0; j<s.size()+1; j++ ) {
				string f = "";
				for ( int k=0; k<j; k++ )
					f.push_back(s[k]);
				f.push_back(i+'0');
				for ( int k=j; k<s.size(); k++ )
					f.push_back(s[k]);
				S.insert(f);
			}
	S.erase(*S.begin());
	while ( S.size() > 1 ) {
		cout << *S.begin() << '\n';
		S.erase(*S.begin());
	}
	return 0;
}

