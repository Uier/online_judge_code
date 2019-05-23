#include <iostream>
#include <vector>
#include <queue>
#define maxn 100005
using namespace std;
vector<int> G[maxn], ans;
bool inque[maxn];
priority_queue<int,vector<int>,greater<int>> PQ;
void dfs(int x) {
	ans.emplace_back(x);
	for ( int i : G[x] )
		if ( !inque[i] ) {
			PQ.push(i);
			inque[i] = 1;
		}
	if ( PQ.empty() )	return;
	int y = PQ.top();	PQ.pop();
	dfs(y);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for ( int i=0, x, y; i<m; ++i ) {
		cin >> x >> y;
		G[x].emplace_back(y);
		G[y].emplace_back(x);
	}
	inque[1] = 1;
	dfs(1);
	for ( int i : ans )	cout << i << ' ';
	cout << '\n';
	return 0;
}

