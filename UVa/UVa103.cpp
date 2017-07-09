#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
int n, d, a[100005][11], D[100005], T[100005];
vector<int> G[100005];
void A_sort(int i) {
	int b[11];
	for ( int j=0; j<d; ++j )
		b[j] = a[i][j];
	sort(b,b+d);
	for ( int j=0; j<d; ++j )
		a[i][j] = b[j];
}
int check(int i, int j) {
	bool small = true, large = true;
	for ( int k=0; k<d; ++k )
		small &= (a[i][k]<a[j][k]);
	if ( small )	return 1;
	for ( int k=0; k<d; ++k )
		large &= (a[i][k]>a[j][k]);
	if ( large )	return -1;
	return 0;
}
void dfs(int x) {
	D[x] = 1;
	for ( int i : G[x] ) {
		if ( D[i] == -1 )
			dfs(i);
		if ( D[i]+1 > D[x] ) {
			D[x] = max(D[x],D[i]+1);
			T[x] = i;
		}
	}
}
void trace(int x) {
	if ( T[x] == -1 )	cout << x << '\n';
	else {
		cout << x << ' ';
		trace(T[x]);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	while ( cin >> n >> d ) {
		memset(a,0,sizeof a);
		memset(D,-1,sizeof D);
		memset(T,-1,sizeof T);
		memset(G,0,sizeof G);
		for ( int i=1; i<=n; ++i ) {
			for ( int j=0; j<d; ++j )
				cin >> a[i][j];
			A_sort(i);
		}
		for ( int i=1; i<=n; ++i )
			for ( int j=i+1; j<=n; ++j ) {
				int flag = check(i,j);
				if ( flag == 1 )	G[i].push_back(j);
				else if ( flag == -1 )	G[j].push_back(i);
			}
		for ( int i=1; i<=n; ++i )
			if ( D[i] == -1 )
				dfs(i);
		int ans = 0, loc = 0;
		for ( int i=1; i<=n; ++i ) {
			if ( D[i] > ans ) {
				ans = D[i];
				loc = i;
			}
		}
		cout << ans << '\n';
		trace(loc);
	}
	return 0;
}

