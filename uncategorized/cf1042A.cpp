#include <iostream>
#include <queue>
using namespace std;
priority_queue<int,vector<int>,greater<int>> PQ;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, mx = 0;
	cin >> n >> m;
	for ( int i=0, x; i<n; ++i ) {
		cin >> x;
		mx = max(mx,x);
		PQ.push(x);
	}
	for ( int i=0; i<m; ++i ) {
		int tmp = PQ.top();	PQ.pop();
		PQ.push(tmp+1);
	}
	for ( int i=1; i<n; ++i )	PQ.pop();
	cout << PQ.top() << ' ' << mx+m << '\n';
	return 0;
}

