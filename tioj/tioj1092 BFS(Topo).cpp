#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#define maxn 10005
using namespace std;
vector<int> G[maxn];
queue<int> Q;
int D[maxn], in[maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, a, b;
	string s;
	while ( cin >> n >> m && (n||m) ) {
		memset(D,0,sizeof(D));
		memset(in,0,sizeof(in));
		for ( int i=1; i<=n; ++i )	G[i].clear();
		while ( m-- && cin >> a >> b ) { // reverse
			G[b].emplace_back(a);
			in[a]++;
		}
		cin >> s;
		D[n] = 1;
		Q.push(n);
		while ( !Q.empty() ) {
			int x = Q.front();	Q.pop();
			for ( int i : G[x] ) {
				if ( D[i] )	D[i] = ((D[i]==1 && D[x]==2) ? 1 : 2);
				else	D[i] = (D[x]==1 ? 2 : 1);
				if ( --in[i] == 0 )	Q.push(i);
			}
		}
		if ( D[1] == 1 )	cout << s << '\n';
		else	cout << (s=="Mimi" ? "Moumou\n" : "Mimi\n");
	}
	return 0;
}

