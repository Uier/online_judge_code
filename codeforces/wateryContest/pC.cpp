#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string.h>
#include <cmath>
#define int long long
using namespace std;
typedef pair<int,int> pii;
int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, ans = 0;
	string s;
	cin >> n >> s;
	for ( int i=0; i<n; ++i ) {
		if ( (s[i]-'0')%2 == 0 ) {
			ans += i+1;
		}
	} 
	cout << ans << '\n';
	return 0;
}

