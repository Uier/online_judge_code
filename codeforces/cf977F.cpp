#include <iostream>
#include <unordered_map>
#include <vector>
#define maxn 200005
using namespace std;
struct num {
	int len, path;
} ans, dp[maxn];
unordered_map<int,int> pos; // the last position i at
vector<int> V;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, x, tar, last;
	cin >> n;
	for ( int i=1; i<=n; ++i ) {
		cin >> x;
		dp[i] = num{1,i};
		pos[x] = i;
		tar = pos[x-1];
		if ( tar != 0 && dp[tar].len+1 > dp[i].len )
			dp[i] = num{dp[tar].len+1,tar};
		if ( dp[i].len > ans.len ) ans = dp[i], last = i;
	}
	int cnt = ans.len;
	V.emplace_back(last);
	while ( --cnt ) {
		V.emplace_back(ans.path);
		ans = dp[ans.path];
	} cout << V.size() << '\n';
	for ( int i=0; i<V.size(); ++i )
		cout << V[V.size()-1-i] << ' ';
	cout << '\n';
	return 0;
} 
