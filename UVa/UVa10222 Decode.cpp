#include <iostream>
using namespace std;
char a[12]={'q','w','e','r','t','y','u','i','o','p','[',']'};
char b[11]={'a','s','d','f','g','h','j','k','l',';','\''};
char c[10]={'z','x','c','v','b','n','m',',','.','/'};
int main()
{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	string s;
	getline(cin,s);
	for ( int i=0; i<s.size(); i++ ) {
		if ( s[i] == ' ' )
			cout << s[i];
		else {
			for ( int j=0; j<12; j++ )
				if ( s[i] == a[j] )
					cout << a[j-2];
			for ( int j=0; j<11; j++ )
				if ( s[i] == b[j] )
					cout << b[j-2];
			for ( int j=0; j<10; j++ )
				if ( s[i] == c[j] )
					cout << c[j-2];
		}
	}
	cout << '\n';
	return 0;
}

