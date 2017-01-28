#include <iostream>
using namespace std;
int n, l, r, kase;
bool v[30];
char a[30];
string s;
void pr() {
	
}
void bt(int l, int r, int x) {
	if ( x == n*2 ) {
		pr();
		return;
	}
	if ( l < n ) {
		s.push_back('(');
		bt(l+1,r,x+1);
		s.pop_back();
	}
}
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	while ( cin >> n ) {
		
	}
	return 0;
}

