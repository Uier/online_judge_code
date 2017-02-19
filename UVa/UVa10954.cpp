#include <iostream>
#include <queue>
using namespace std;
priority_queue<int,vector<int>,greater<int>> Q;
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int n, a;
	while ( cin >> n && n ) {
		long long ans = 0;
		for ( int i=0; i<n; i++ ) {
			cin >> a;
			Q.push(a);
		}
		while ( Q.size() > 1 ) {
			int b = Q.top();	Q.pop();
			int c = Q.top();	Q.pop();
			Q.push(b+c);
			ans += b+c;
		}
		cout << ans << '\n';
		Q.pop();
	}
	return 0;
}

