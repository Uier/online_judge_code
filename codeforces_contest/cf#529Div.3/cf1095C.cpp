#include <iostream>
#include <queue>
using namespace std;
int dp[31];
priority_queue<int> arr;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	dp[0] = 1;
	for ( int i=1; i<31; ++i )	dp[i] = dp[i-1]<<1;
	int n, k;
	cin >> n >> k;
	if ( k > n )	return cout << "NO\n", 0;
	for ( int i=30; i>=0; --i )
		if ( n >= dp[i] ) {
			arr.push(dp[i]);
			n -= dp[i];
		}
	if ( arr.size() > k )	return cout << "NO\n", 0;
	else {
		cout << "YES\n";
		int rem = k-arr.size();
		while ( rem-- ) {
			int x = arr.top();	arr.pop();
			arr.push(x/2);
			arr.push(x/2);
		}
		while ( !arr.empty() ) {
			cout << arr.top() << ' ';
			arr.pop();
		}
		cout << '\n';
	}
	return 0;
}


