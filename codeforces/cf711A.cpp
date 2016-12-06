#include <iostream>
using namespace std;
string s[1005];
int main()
{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int n, a=0;
	bool c=true;
	cin >> n;
	for ( int i=0; i<n; i++ ) {
		cin >> s[i];
		if ( s[i][0]==s[i][1] && s[i][1]=='O' && c ) {
			a = i;
			s[i][0] = '+';
			s[i][1] = '+';
			c = false;
		}
		else if ( s[i][3]==s[i][4] && s[i][4]=='O' && c ) {
			a = i;
			s[i][3] = '+';
			s[i][4] = '+';
			c = false;
		}
	}
	if ( c )
		cout << "NO" << '\n';
	else {
		cout << "YES" << '\n';
		for ( int i=0; i<n; i++ )
			cout << s[i] << '\n';
	}
	return 0;
}

