#include <iostream>
#include <vector>
using namespace std;
vector<int> G[500];
int W[500], fa[500], in[500], out[500], A[1000], B[1000], cnt;
void dfs(int x) {
	in[x] = cnt;
	A[cnt++] = W[x];
	for ( int i : G[x] )
		if ( i != fa[x] ) {
			fa[i] = x;
			dfs(i);
		}
	out[x] = cnt;
	A[cnt++] = -W[x];
}
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int n;
	cin >> n;
	for ( int i=1; i<n; ++i ) {
		int a, b;
		cin >> a >> b;
		G[a].emplace_back(b);
		G[b].emplace_back(a);
	}
	for ( int i=1; i<=n; ++i )
		cin >> W[i];
	fa[1] = -1;
	dfs(1);
	B[0] = A[0];
	for ( int i=0; i<n*2; ++i ) {
		cout << A[i] <<' ';
		if ( i )	B[i] = B[i-1] + A[i];
	}
	cout << '\n';
	cout << "ask the cost of going v from root(1)\n";
	int v;
	cin >> v;
	cout << B[v[in]] << '\n';	
	return 0;
}

