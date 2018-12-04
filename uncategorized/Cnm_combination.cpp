#include <iostream>
#define maxn 1005
using namespace std;
int n, m, arr[maxn], s[maxn];
bool vis[maxn]; 
void print() {
	for ( int i=0; i<m; ++i )	cout << s[i] << ' ';
	cout << '\n';
}
void dfs(int x, int l) {
	if ( x == m ) {
		print();
		return;
	}
	for ( int i=l; i<=n; ++i )
		if ( !vis[i] ) {
			vis[i] = true;
			s[x] = i;
			dfs(x+1,i+1);
			vis[i] = false;
		}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	dfs(0,1);
	return 0;
}

