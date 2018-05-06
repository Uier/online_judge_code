#include <iostream>
using namespace std;
int a[500];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	while ( cin >> s ) {
		for ( int i=0; i<500; ++i )	a[i] = 0;
		int l = s.size();
		for ( int i=0; i<l; ++i ) {
			if (s[i] >= 'a' && s[i] <= 'z')
				a[s[i]]++;
			else if (s[i] >= 'A' && s[i] <= 'Z')
				a[s[i]+32]++;
		}
		int cnt = 0;
		for ( int i=0; i<500; ++i ) {
			if ( a[i]%2 )	cnt++;
		}
		if ( cnt > 1 )	cout << "no...\n";
		else	cout << "yes !\n";
	}
	return 0;
}

