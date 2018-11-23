#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#define int long long
#define maxn 200005
using namespace std;
set<int> S;
map<int,int> M;
int ans[maxn];
main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	for ( int i=0, x; i<n; ++i ) {
		cin >> x;
		S.insert(x);
		M[x] = i;
	}
	int cnt = 0;
	while ( !S.empty() ) {
		cnt++;
		auto pos = S.begin();
		while ( pos != S.end() ) {
			int tmp = *pos;
			ans[M[tmp]] = cnt;
			S.erase(pos);
			pos = S.upper_bound(tmp+k);
		}
	}
	cout << cnt << '\n';
	for ( int i=0; i<n; ++i )
		cout << ans[i] << ' ';
	cout << '\n';
	return 0;
}

