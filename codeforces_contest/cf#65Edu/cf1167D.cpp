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
	int n, r = 0, b = 0;
//	int dep = 0;
	string s, ans = "";
	cin >> n >> s;
	for ( int i=0; i<n; ++i ) {
		if ( s[i] == '(' ) {
			if ( r > b ) {
				b++;
				ans.push_back('1');
			} else {
				r++;
				ans.push_back('0');
			}
		} else {
			if ( r > b ) {
				r--;
				ans.push_back('0');
			} else {
				b--;
				ans.push_back('1');
			}
		}
//		dep = max(dep,max(r,b));
	}
	cout << ans << '\n';
	return 0;
}

