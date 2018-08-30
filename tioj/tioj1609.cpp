#include <iostream>
#include <queue>
using namespace std;
priority_queue<int,vector<int>,greater<int>> PQ;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for ( int i=0, x; i<n; ++i ) {
		cin >> x;
		PQ.push(x);
	}
	cout << PQ.top();	PQ.pop();
	while ( !PQ.empty() ) {
		cout << ' ' << PQ.top();
		PQ.pop();
	}
	cout << '\n';
	return 0;
}

