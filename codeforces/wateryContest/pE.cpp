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
	string s;
	cin >> s;
	int n = s.size(), cnt = 0;;
	for ( int i=0; i<n; ++i )	if ( s[i] == 'a' )	cnt++;
	if ( cnt > n/2 )	cout << n << '\n';
	else	cout << cnt*2-1 << '\n';
	return 0;
}

