#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
struct node {
	vector<string> arr;
	int dist;
};
int n, l, cs = 1;
vector<string> plug, elec;
map<vector<string>,int> D;
int bfs() {
	if ( plug == elec )	return 0;
	queue<node> Q;
	D[plug] = 1;
	Q.push(node{plug,1});
	while ( !Q.empty() ) {
		node tmp = Q.front();	Q.pop();
		vector<string> v = tmp.arr;
		int d = tmp.dist;
		for ( int i=0; i<l; ++i ) {
			for ( int j=0; j<n; ++j )
				v[j][i] = (v[j][i]=='0' ? '1' : '0');
			sort(v.begin(),v.end());
			if ( !D[v] ) {
				if ( v == elec )	return d;
				D[v] = d+1;
				Q.push(node{v,d+1});
			}
			for ( int j=0; j<n; ++j )
				v[j][i] = (v[j][i]=='0' ? '1' : '0');
		}
	}
	return -1;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while ( t-- && cin >> n >> l ) {
		for ( int i=0; i<n; ++i ) {
			string tmpp;	cin >> tmpp;
			plug.emplace_back(tmpp);
		}
		for ( int i=0; i<n; ++i ) {
			string tmpp;	cin >> tmpp;
			elec.emplace_back(tmpp);
		}
		sort(plug.begin(),plug.end());
		sort(elec.begin(),elec.end());
		cout << "Case #" << cs++ << ": ";
		int ans = bfs();
		if ( ans == -1 )	cout << "IMPOSSIBLE\n";
		else	cout << ans << '\n';
		plug.clear();
		elec.clear();
		D.clear();
	}
	return 0;
}

