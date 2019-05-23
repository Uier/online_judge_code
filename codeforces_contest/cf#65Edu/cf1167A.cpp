#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string.h>
#include <cmath>
using namespace std;
typedef pair<int,int> pii;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t, n;
	string s;
	cin >> t;
	while ( t-- && cin >> n >> s) {
		int op = n-11, cnt = 0;
		for ( int i=0; i<n; ++i ) {
			if ( s[i] != '8' )	cnt++;
			else	break;
		}
		if ( cnt <= op )	cout << "YES\n";
		else	cout << "NO\n";
	}
	return 0;
}

