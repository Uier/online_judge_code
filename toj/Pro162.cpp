#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, r[3][3];
	string a, b;
	cin >> t;
	while ( t-- ) {
		bool pa=false, pb=false;
		getline(cin,a);
		getline(cin,a);
		getline(cin,b);
		for ( int i=0; i<3; i++ )
			for ( int j=0; j<3; j++ )
				cin >> r[i][j];
		for ( int i=0; i<3; i++ ) {
			if ( r[i][0]==r[i][1]&&r[i][1]==r[i][2] ) {
				if ( r[i][0] == 1 )
					pa = true;
				else if ( r[i][0] == 0 )
					pb = true;
			}
			if ( r[0][i]==r[1][i]&&r[1][i]==r[2][i] ) {
				if ( r[0][i] == 1 )
					pa = true;
				else if ( r[0][i] == 0 )
					pb = true; 
			}
		}
		if ( r[0][0]==r[1][1]&&r[1][1]==r[2][2] ) {
			if ( r[0][0] == 1 )
				pa = true;
			else if ( r[0][0] == 0 )
				pb = true;
		}
		if ( r[0][2]==r[1][1]&&r[1][1]==r[2][0] ) {
			if ( r[0][2] == 1 )
				pa = true;
			else if ( r[0][2] == 0 )
				pb = true;
		}
		if ( pa && pb )
			cout << "Impossible\n";
		else if ( pa )
			cout << a << '\n';
		else if ( pb )
			cout << b << '\n';
		else
			cout << "Not yet\n";
	}
	return 0;
}

