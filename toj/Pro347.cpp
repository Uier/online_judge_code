#include <iostream>
using namespace std;
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int n;
	string s;
	cin >> n;
	getline(cin,s);	
	while ( n-- ) {
		getline(cin,s);
		for ( int i=0; i<s.size(); i++ )
			if ( s[i] >= 65 && s[i] <= 90 )
				s[i] += 32;
		cout << s << '\n';
	}
	return 0;
}

