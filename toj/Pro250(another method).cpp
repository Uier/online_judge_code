// wa
#include <iostream>
#include <queue>
using namespace std;
int a[1000005];
typedef pair<int,int> pii;
priority_queue<pii> Q;
bool operator < (pii a, pii b) {
	if ( a.first == b.first )	return a.second < b.second;
	return a.first < b.first;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	for ( int i=1; i<=n; i++ )
		Q.push({0,i});
	while ( q-- ) {
		int t, k, v;
		cin >> t;
		if ( t == 1 ) {
			cin >> k >> v;
			a[k] += v;
			Q.push({a[k],k});
		} else {
			cin >> v;
			pii tmp = Q.top();	Q.pop();
			a[tmp.second] -= v;
			Q.push({a[tmp.second],tmp.second});
		}
	}
	for ( int i=1; i<=n; i++ )
		cout << a[i] << '\n';
	return 0;
}

