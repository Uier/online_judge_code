#include <iostream>
#include <stack>
#define maxn 1000005
using namespace std;
typedef pair<int,int> pii;
stack<pii> S;
int dp[maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, x;
	long long sum = 0;
	cin >> n >> x;
	S.push(pii{x,0});
	dp[0] = 0;
	for ( int i=1; i<n; ++i ) {
		cin >> x;
		if ( x < S.top().first ) {
			S.push(pii{x,i});
			dp[i] = 1;
			sum += 1;
		} else if ( x > S.top().first ) {
			while ( !S.empty() && x > S.top().first ) {
				sum++;
				S.pop();
			}
			if ( !S.empty() )
				if ( x == S.top().first )
					dp[i] += dp[S.top().second]+1;
				else
					dp[i]++;
			S.push(pii{x,i});
			sum += dp[i];
		} else {
			S.push(pii{x,i});
			dp[i] = dp[i-1]+1;
			sum += dp[i];
		}
	}
	cout << sum*2 << '\n';
	return 0;
}

