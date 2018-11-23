#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#define maxn 1005 
using namespace std;
int D[maxn];
typedef pair<int,int> pii;
vector<int> prm;
queue<pii> Q;
inline void bfs(int t) {
	while ( !Q.empty() ) {
		pii tmp = Q.front();	Q.pop();
		if ( tmp.second > D[tmp.first] )	continue;
		int x = tmp.first;
		for ( int i : prm ) {
			if ( x+i > t || i >= x )	break;
			if ( x%i || D[x]+1 >= D[x+i] )	continue;
			D[x+i] = D[x]+1;
			Q.push(make_pair(x+i,D[x+i]));
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	for ( int i=2; i<maxn; ++i ) {
		bool flag = true;
		for ( int j=2; j*j<=i; ++j )	if ( i%j == 0 )	flag = false;
		if ( flag )	prm.emplace_back(i);
	}
	int s, t, cs = 1;
	while ( cin >> s >> t && (s||t) ) {
		memset(D,0x3f,sizeof(D));
		Q.push(make_pair(s,D[s]=0));
		bfs(t);
		if ( D[t] == D[0] )	cout << "Case " << cs++ << ": " << -1 << '\n';
		else	cout << "Case " << cs++ << ": " << D[t] << '\n';
	}
	return 0;
}

