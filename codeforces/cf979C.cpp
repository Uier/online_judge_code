#include <iostream>
#include <vector>
#define maxn 300005
using namespace std;
vector<int> G[maxn];
long long fl, be, mid;
bool D[maxn], f_of_b[maxn];
bool dfs(int x, int fa, bool bees) {
	if ( x == be )	bees = true;
	D[x] = bees;
	for ( int i : G[x] )
		if ( i != fa )
			f_of_b[x] = (f_of_b[x]||dfs(i,x,bees));
	return ((x==be||f_of_b[x]) ? 1 : 0);
}
void dfs2(int x, int fa) {
	long long child = 0;
	for ( int i : G[x] )
		if ( i != fa ) {
			dfs2(i,x);
			child++;
		}
	if ( x == fl ) mid += 1;
	else if ( f_of_b[x] )	mid += child;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n, a, b;
	cin >> n >> fl >> be;
	for ( int i=1; i<n; ++i ) {
		cin >> a >> b;
		G[a].emplace_back(b);
		G[b].emplace_back(a);
	}
	dfs(fl,0,false);
	long long child_of_bee = 0;
	for ( int i=1; i<=n; ++i )
		if ( D[i] )	child_of_bee++;
	dfs2(fl,0);
	long long now_flower = mid + child_of_bee-1;
	long long flowers = n-mid;
	long long gg = child_of_bee * flowers;
	cout << n*(n-1)-gg << '\n';
	return 0;
}

