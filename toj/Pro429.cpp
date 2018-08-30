#include <iostream>
#include <map>
#include <queue>
using namespace std;
map<string,int> M;
queue<string> Q;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string st = "012345678";
	M[st] = 1;
	Q.push(st);
	while ( !Q.empty() ) {
		string t = Q.front();	Q.pop();
		int pos = 0, dep = M[t];
		for ( int i=1; i<9; ++i )	if ( t[i] == '0' )	pos = i;
		if ( (pos+2)%3 != 2 ) { // left
			swap(t[pos],t[pos-1]);
			if ( M[t] == 0 ) {
				M[t] = dep+1;
				Q.push(t);
			}
			swap(t[pos],t[pos-1]);
		}
		if ( (pos+1)%3 != 0 ) { // right
			swap(t[pos],t[pos+1]);
			if ( M[t] == 0 ) {
				M[t] = dep+1;
				Q.push(t);
			}
			swap(t[pos],t[pos+1]);
		}
		if ( pos-3 >= 0 ) { // up
			swap(t[pos],t[pos-3]);
			if ( M[t] == 0 ) {
				M[t] = dep+1;
				Q.push(t);
			}
			swap(t[pos],t[pos-3]);
		}
		if ( pos+3 <= 8 ) { // down
			swap(t[pos],t[pos+3]);
			if ( M[t] == 0 ) {
				M[t] = dep+1;
				Q.push(t);
			}
			swap(t[pos],t[pos+3]);
		}
	}
	int t;
	cin >> t;
	while ( t-- ) {
		string s;
		for ( int i=0, x; i<9; ++i ) cin >> x, s += char('0'+x);
		if ( M[s] == 0 )	cout << "QQ\n";
		else	cout << M[s]-1 << '\n';
	}
	return 0;
}

