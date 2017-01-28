#include <iostream>
using namespace std;
int n, l, r, kase;
bool v[30];
char a[30];
string s;
void bt(int l, int r, int x) {
	if ( x == n*2 ) {
		for ( int i=0; i<n*2; i++ )
			cout << s[i];
		cout << '\n';
		return;
	}
	if ( l < n ) {
		s.push_back('(');
		bt(l+1,r,x+1);
		s.pop_back();
	}
	if ( l > r && r < n ) {
		s.push_back(')');
		bt(l,r+1,x+1);
		s.pop_back();	
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	while ( cin >> n ) {
		bt(0,0,0);
		cout << '\n';
	}
	return 0;
}

