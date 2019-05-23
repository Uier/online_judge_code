#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string.h>
#include <cmath>
#include <set>
#define maxn 1000005
#define int long long
using namespace std;
typedef pair<int,int> pii;
set<int> S;
int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, x;
	cin >> n >> x;
	int ans = n*(n+1)/2;
	int l = x, r;
	for ( int i=0, tmp; i<n; ++i ) {
		cin >> tmp;
		S.insert(tmp);
		if ( S.upper_bound(tmp) == S.end() )	continue;
		l = min(l,*S.upper_bound(tmp));
		r = *S.rbegin();
//		cout << "l,r: " << l << ' ' << r << '\n';
		int sum = tmp*(x-tmp+1)+l*(x-r+1)-tmp*(x-r+1);
//		cout << i << ' ' << sum << '\n';
		ans = min(ans,sum);
	}
	cout << ans << '\n';
	return 0;
}

