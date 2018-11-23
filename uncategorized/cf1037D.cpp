#include <iostream>
#include <set>
#include <queue>
#define maxn 200005
using namespace std;
typedef pair<int,int> pii;
int arr[maxn], D[maxn];
set<int> G[maxn];
queue<pii> Q;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for ( int i=1, x, y; i<n; ++i ) {
		cin >> x >> y;
		G[x].insert(y);
		G[y].insert(x);
	}
	for ( int i=0; i<n; ++i )	cin >> arr[i];
	int pt = 0;
	if ( arr[pt++] != 1 )	return cout << "No\n", 0;
	G[1].insert(1);
	Q.push(pii{1,1});
	while ( !Q.empty() ) {
		pii tmp = Q.front();	Q.pop();
		int x = tmp.first, y = tmp.second;
		for ( int i=1; i<G[x].size(); ++i ) {
			if ( G[x].find(arr[pt]) == G[x].end() )
				return cout << "No\n", 0;
			Q.push(pii{arr[pt++],x});
		}
	}
	cout << "Yes\n";
	return 0;
}

