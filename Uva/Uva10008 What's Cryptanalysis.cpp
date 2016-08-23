#include <iostream>
#include <algorithm>
using namespace std;
int a[200];
struct d {
	int x, y;
} b[30];
bool cmp(d a, d b) {
	if ( a.y != b.y )
		return a.y > b.y;
	return a.x < b.x;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	string s;
	getline(cin,s);
	while ( n-- ) {
		getline(cin,s);
		for ( int i=0; i<s.size(); i++ ) {
			if ( s[i] >= 97 )
				a[s[i]-32]++;
			else
				a[s[i]]++;
		}		
	}
	int j=0;
	for ( int i=65; i<=90; i++ )
		if ( a[i] != 0 ) {
			b[j].x = i;
			b[j++].y = a[i];
		}
	sort(b,b+j,cmp);
	for ( int i=0; i<j; i++ )
		cout << char(b[i].x) << ' ' << b[i].y << '\n';
	return 0;
}

