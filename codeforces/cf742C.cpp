#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int D, n, a;
long long ans;
bool V[105];
vector<int> G[105];
vector<int> C;
void dfs(int x, int d) {
	D = max(D,d);
	for ( int i : G[x] )
		if ( !V[i] ) {
			V[i] = true;
			dfs(i,d+1);
		}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for ( int i=0; i<n; i++ ) {
		cin >> a;
		G[i+1].push_back(a);
		G[a].push_back(i+1);
	}
	bool crt = true;
	for ( int i=1; i<=n; i++ )
		if ( !V[i] ) {
			D = 0;
			dfs(i,0);
//			if ( D == 1 )
//				crt = false;
			while ( D%2 == 0 )
				D /= 2;
			C.push_back(D);
		}
	ans = 1;
	for ( int i : C )
		ans *= i;
	if ( crt )	cout << ans << '\n';
	else	cout << -1 << '\n';
	return 0;
}

