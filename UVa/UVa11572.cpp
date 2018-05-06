#include <iostream>
#include <unordered_map>
using namespace std;
unordered_map<int,int> pos;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, n, x, l, cnt, ans;
	cin >> t;
	while ( t-- && cin >> n ) {
		l = cnt = ans = 0;
		pos.clear();
		while ( n-- && cin >> x ) {
			l = max(l,pos[x]);
			pos[x] = ++cnt;
			ans = max(ans,cnt-l);
		}
		cout << ans << '\n';
	}
	return 0;
}

