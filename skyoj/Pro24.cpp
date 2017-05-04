#include <iostream>
#include <string.h>
using namespace std;
int fail[50000001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	while ( cin >> s ) {
		memset(fail,-1,sizeof fail);
		int j = fail[0] = -1;
		for ( int i=1; i<s.size(); i++ ) {
			while ( j != -1 && s[i] != s[j+1] )	j = fail[j];
			if ( s[i] == s[j+1] )	j++;
			fail[i] = j;
		}
		if ( s.size()%(s.size()-(fail[s.size()-1]+1)) )	cout << s;
		else
			for ( int i=0; i<s.size()-(fail[s.size()-1]+1); i++ )	cout << s[i];
		cout << '\n';
	}
	return 0;
}

