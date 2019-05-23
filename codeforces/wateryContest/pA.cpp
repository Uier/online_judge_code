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
	int n, v, m, cur = 0, ans = 0;
	cin >> n >> v;
	m = n-1;
	for ( int i=1; i<=n; ++i, --cur ) {
		if ( v-cur >= m ) {
			ans += i*m;
			break;
		} else {
			m -= v-cur;
			ans += i*(v-cur);
			cur = v;
		}
	}
	cout << ans << '\n';
	return 0;
}

