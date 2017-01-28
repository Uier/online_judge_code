#include <iostream>
using namespace std;
int a[30][30][30][30][30], x=1;
int main()
{
	for ( int i=1; i<=26; i++ )
		a[i][0][0][0][0] = x++;
	for ( int i=1; i<=26; i++ )
		for ( int j=i+1; j<=26; j++ )
			a[i][j][0][0][0] = x++;
	for ( int i=1; i<=26; i++ )
		for ( int j=i+1; j<=26; j++ )
			for ( int k=j+1; k<=26; k++ )
				a[i][j][k][0][0] = x++;	
	for ( int i=1; i<=26; i++ )
		for ( int j=i+1; j<=26; j++ )
			for ( int k=j+1; k<=26; k++ )
				for ( int l=k+1; l<=26; l++ )
					a[i][j][k][l][0] = x++;
	for ( int i=1; i<=26; i++ )
		for ( int j=i+1; j<=26; j++ )
			for ( int k=j+1; k<=26; k++ )
				for ( int l=k+1; l<=26; l++ )
					for ( int m=l+1; m<=26; m++ )
						a[i][j][k][l][m] = x++;
	string s;
	bool c;
	while ( cin >> s ) {
		int b[5]={0, 0, 0, 0, 0};
		c = false;
		for ( int i=0; i<s.size(); i++ ) {
			if ( i != 0 && s[i] <= s[i-1] )
				c = true;
			else
				b[i] = s[i]-'a'+1;
		}
		if ( c )
			cout << 0 << '\n';
		else
			cout << a[b[0]][b[1]][b[2]][b[3]][b[4]] << '\n';
	}
	return 0;
}

