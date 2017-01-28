#include <iostream>
using namespace std;
int a[50], s[6], k=0;
bool u[15];
void print() {
	for ( int i=0; i<5; i++ )
		cout << s[i] << ' ';
	cout << s[5] << '\n';
}
void backtrack(int x) {
	if ( x == 6 ) {
		print();
		return;
	}
	for ( int i=x; i<x+1+k-6; i++ )
		if ( !u[i] && a[i] > s[x-1] ) {
			s[x] = a[i];
			u[i] = true;
			backtrack(x+1);	
			u[i] = false;
		}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	bool f=1;
	while ( cin >> k && k) {
		if ( k == 0 )
			break;
		if ( !f )
			cout << '\n';
		if ( f )
			f = 0;
		for ( int i=0; i<k; i++ )
			cin >> a[i];
		for ( int i=0; i<50; i++ )
			u[i] = false;
		backtrack(0);
	}
	return 0;
}

