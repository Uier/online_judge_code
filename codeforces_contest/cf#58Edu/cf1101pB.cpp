#include <iostream>
#include <stack>
using namespace std;
stack<char> stk;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	char tar[4] = {'[', ':', ':', ']'};
	string s;
	cin >> s;
	int cnt = 0, len = s.size();
	for ( int i=0; i<len; ++i )
		if ( cnt < 4 && s[i] == tar[cnt] )	cnt++;
	if ( cnt < 4 )	return cout << -1 << '\n', 0;
	int lbr = 0, rbr = len-1;
	while ( s[lbr] != '[' )	lbr++;
	while ( s[rbr] != ']' )	rbr--;
	int lcl = lbr, rcl = rbr;
	while ( s[lcl] != ':' )	lcl++;
	while ( s[rcl] != ':' )	rcl--;
	int ans = lcl+len-1-rcl-2;
	for ( int i=lcl+1; i<rcl; ++i )	if ( s[i] != '|' )	ans++;
	cout << len-ans << '\n';
	return 0;
}

