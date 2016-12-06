#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	long long n=0;
	for ( long long i=s.size()-2, j=1; i>=0; i--, j*=10 ) {
		long long m = (s[i]-'0');
		n += m*j;
	}
	n -= 1;
	long long sec = (n/4)*12+1+(n/4)*2+(n/4)*2;
	if ( n%2 == 1 )
		sec += 7;
	if ( s[s.size()-1] == 'a' )
		sec += 3;
	else if ( s[s.size()-1] == 'b' )
		sec += 4;
	else if ( s[s.size()-1] == 'c' )
		sec += 5;	
	else if ( s[s.size()-1] == 'd' )
		sec += 2;
	else if ( s[s.size()-1] == 'e' )
		sec += 1;
	cout << sec << '\n';
	return 0;
}

