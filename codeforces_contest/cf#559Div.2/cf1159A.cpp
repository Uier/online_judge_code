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
	int n, ans = 0;
	string s;
	cin >> n >> s;
	for ( int i=0; i<s.size(); ++i ) {
		if ( s[i] == '-' ) {
			ans--;
			if ( ans < 0 )	ans = 0;
		} else {
			ans++;
		}
	}
	cout << ans << '\n';
	return 0;
}

