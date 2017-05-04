#include <iostream>
using namespace std;
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	string s;
	int tmp = 0;
	cin >> s;
	for ( int i=0; i<s.size()/2; ++i )
		if ( s[i] != s[s.size()-1-i] )
			tmp++;
	if ( tmp == 1 || (tmp == 0 && s.size()%2 == 1) )
		puts("YES");
	else
		puts("NO");
	return 0;
}

