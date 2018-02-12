#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
struct block {
	int len, wid;
} arr[100];
int W[100], in[100];
vector<int> G[100];
bool operator < (block x, block y) {
	return ((x.len < y.len && x.wid < y.wid) || (x.len < y.wid && x.wid < y.len));
}
int dfs(int x) {
	int sum = 0;
	for ( int i : G[x] )
		sum = max(sum,dfs(i));
	return W[x]+sum;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, a, b, c, t = 1;
	while ( cin >> n && n ) {
		int cnt = 0;
		memset(G,0,sizeof(G));
		memset(W,0,sizeof(W));
		memset(in,0,sizeof(in));
		for ( int i=0; i<n; ++i ) {
			cin >> a >> b >> c;
			W[cnt] = c;	arr[cnt++] = {a,b};
			W[cnt] = b;	arr[cnt++] = {a,c};
			W[cnt] = a;	arr[cnt++] = {b,c};
		}
		for ( int i=0; i<cnt; ++i )
			for ( int j=0; j<cnt; ++j )
				if ( arr[i] < arr[j] ) {
					G[i].emplace_back(j);
					in[j]++;
				}
		int ans = 0;
		for ( int i=0; i<cnt; ++i )
			if ( in[i] == 0 )
				ans = max(ans,dfs(i));
		cout << "Case " << t++ << ": maximum height = " << ans << '\n';
	}
	return 0;
}

