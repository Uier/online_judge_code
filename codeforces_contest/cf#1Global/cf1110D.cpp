#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#define maxn 1000005
using namespace std;
int cnt[maxn], dp[maxn][3][3];
vector<int> arr;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, ans = 0;
	cin >> n >> m;
	for ( int i=0, x; i<n; ++i ) {
		cin >> x;
		if ( cnt[x] == 0 )	arr.emplace_back(x);
		cnt[x]++;
	}
	sort(arr.begin(),arr.end());
	int sz = arr.size();
	for ( int i=0; i<sz; ++i ) {
		if ( i == 0 ) {
			dp[i][(cnt[arr[i]]+3)%3][0] = cnt[arr[i]]/3;
			dp[i][(cnt[arr[i]]+2)%3][0] = (cnt[arr[i]]-1)/3;
			dp[i][(cnt[arr[i]]+1)%3][0] = (cnt[arr[i]]-2)/3;
		} else if ( i == 1 ) {
			if ( arr[i-1] == arr[i]-1 ) {
				for ( int j=0; j<3; ++j ) {
					dp[i][(cnt[arr[i]]+3)%3][j] = cnt[arr[i]]/3+dp[i-1][j][0];
					dp[i][(cnt[arr[i]]+2)%3][j] = (cnt[arr[i]]-1)/3+dp[i-1][j][0];
					dp[i][(cnt[arr[i]]+1)%3][j] = (cnt[arr[i]]-2)/3+dp[i-1][j][0];
				}
			} else {
				dp[i][(cnt[arr[i]]+3)%3][0] = cnt[arr[i]]/3;
				dp[i][(cnt[arr[i]]+2)%3][0] = (cnt[arr[i]]-1)/3;
				dp[i][(cnt[arr[i]]+1)%3][0] = (cnt[arr[i]]-2)/3;
			}
		} else {
			if ( arr[i-1] == arr[i]-1 && arr[i-2] == arr[i]-2 ) {
				int base = 0;
				if ( cnt[arr[i]] > 3 )	base = cnt[arr[i]]/3;
				if ( cnt[arr[i]] == 1 ) {
					dp[i][0][1] = base+dp[i-1][2]
				}
			} else if ( arr[i-1] == arr[i]-1 ) {
				for ( int j=0; j<3; ++j ) {
					dp[i][(cnt[arr[i]]+3)%3][j] = cnt[arr[i]]/3+dp[i-1][j][0];
					dp[i][(cnt[arr[i]]+2)%3][j] = (cnt[arr[i]]-1)/3+dp[i-1][j][0];
					dp[i][(cnt[arr[i]]+1)%3][j] = (cnt[arr[i]]-2)/3+dp[i-1][j][0];
				}
			} else {
				dp[i][(cnt[arr[i]]+3)%3][0] = cnt[arr[i]]/3;
				dp[i][(cnt[arr[i]]+2)%3][0] = (cnt[arr[i]]-1)/3;
				dp[i][(cnt[arr[i]]+1)%3][0] = (cnt[arr[i]]-2)/3;
			}
		}
	}
	return 0;
}

