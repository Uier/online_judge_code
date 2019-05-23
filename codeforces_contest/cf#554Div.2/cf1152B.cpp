#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;
int dp[30];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	dp[0] = 1;
	for ( int i=1; i<30; ++i )	dp[i] = dp[i-1]<<1;
	int x, t = 0, pos;
	vector<int> ans;
	ans.clear();
	cin >> x;
	while ( 1 ) {
		pos = lower_bound(dp,dp+30,x+1)-dp;
		if ( pos < 30 && dp[pos] == x+1 ) {
			cout << t << '\n';
			for ( int i : ans )	cout << i << ' ';
			cout << '\n';
			break;
		}
		
		x ^= dp[pos]-1;
		t++;
		ans.emplace_back(pos);
		
		pos = lower_bound(dp,dp+30,x+1)-dp;
		if ( pos < 30 && dp[pos] == x+1 ) {
			cout << t << '\n';
			for ( int i : ans )	cout << i << ' ';
			cout << '\n';
			break;
		}
		
		x++;
		t++;
	}
	return 0;
}

