#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#include <map>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	string s;
	cin >> n >> s;
	int d = n-11;
	int op = d/2, cnt = 0;
	for ( int i=0; i<op*2+1&&i<n; ++i ) {
		if ( s[i] == '8' )	cnt++;
	}
	if ( cnt > op )	cout << "YES\n";
	else	cout << "NO\n";
	return 0;
}

