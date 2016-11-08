#include <iostream>
#include <string.h>
#include <stack>
using namespace std;
string str;
int s[200], sum;
bool V[200];
stack<int> A;
bool check() {
	for ( int i=1; i<=sum; i++ )
		if ( !V[i] )
			return false;
	return true;
}
bool dfs(int x, bool de) {
//	cout << "x: " << x << " de: " << de << " s: " << s[x] << '\n';
	int value = s[x];
	if ( value == 0 )	return false;
	if ( de && x+1 < str.size() )	value = value*10 + s[++x]; 
	if ( value < 1 || value > sum || V[value] ) 	return false;
	V[value] = true;
//	cout << "the value now is: " << value << '\n';
	if ( x == str.size()-1 ) {
		if ( !check() )	return false;
		A.push(value);
		return true;
	}
	if ( dfs(x+1,false) || dfs(x+1,true) )	A.push(value);
	else {
		V[value] = false;
		return false;
	}
	return true;
}
int main() {
  	  ios::sync_with_stdio(false);
  	  cin.tie(0);
	cin >> str;
	while ( !A.empty() )	A.pop();
	memset(s,0,sizeof s);
	memset(V,false,sizeof V);
	for ( int i=0; i<str.size(); i++ )
		s[i] = str[i]-'0';
	if ( str.size() < 10 )	sum = str.size();
	else	sum = (str.size()-9)/2+9;
	if ( !dfs(0,false) )	dfs(0,true);
	while ( A.size() > 1 ) {
		cout << A.top() << ' ';
		A.pop();
	}
	cout << A.top() << '\n';
	return 0;
}

