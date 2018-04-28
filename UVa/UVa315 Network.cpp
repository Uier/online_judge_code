#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
#define maxn 100
using namespace std;
vector<int> G[100];
int N, cnt = 0, A[maxn], D[maxn], L[maxn];
void dfs(int x, int fa, int dep) {
	D[x] = L[x] = dep;
	int child = 0;
	for ( int i : G[x] )
		if ( i != fa ) {
			if ( D[i] )	L[x] = min(L[x],D[i]); // back edge
			else { // tree edge
				child++;
				dfs(i,x,dep+1);
				L[x] = min(L[x],L[i]);
				if ( x != 1 && D[x] <= L[i] )
					A[x] = cnt;
			}
		}
	if ( x == 1 && child >= 2 ) A[1] = cnt;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	while ( cin >> N && N && ++cnt ) {
		getline(cin,s);
		for ( int i=1; i<=N; ++i )	G[i].clear();
		memset(D,0,sizeof(D));
		memset(L,0,sizeof(L));
		while ( getline(cin,s) && s != "0" ) {
			stringstream ss(s);
			int x, y;	ss >> x;
			while ( ss >> y ) {
				G[x].emplace_back(y);
				G[y].emplace_back(x);
			}
		}
		dfs(1,0,1); // set 1 as root
		int ans = 0;
		for ( int i=1; i<=N; ++i )
			if ( A[i] == cnt )
				ans++;
		cout << ans << '\n';
	}
	return 0;
}