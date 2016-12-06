#include <iostream>
#include <string.h>
#include <vector>
#include <stack>
using namespace std;
struct edge {
	int to, cost;
};
int n, m, T, d[5010];
stack<int> A;
vector<edge> G[5010];
vector<int> rG[5010];
void dfs(int s, int p, long long t) {
	if ( s != n )
		for ( edge i : G[s] )
			if ( t+i.cost <= T ) {
				d[i.to] = max(d[i.to],p);
				dfs(i.to,p+1,t+i.cost);
			}
}
void rdfs(int s) {
	if ( s != 1 )
		for ( int i : rG[s] )
			if ( d[i] == d[s]-1 ) {
				A.push(i);
				sec_dfs(i);
				return;
			}
}
int main() {
	  ios::sync_with_stdio(0);
	  cin.tie(0);
	  
	cin >> n >> m >> T;
	while ( m-- ) {
		int a, b, c;
		cin >> a >> b >> c;
		G[a].push_back({b,c});
		rG[b].push_back(a);
	}
	d[1] = 1;
	dfs(1,2,0);
	
	A.push(n);
	rdfs(n);
	
	cout << A.size() << '\n';
	while ( !A.empty() ) {
		cout << A.top();
		A.pop();
		A.empty() ? cout<<'\n' : cout<<' ';
	}
	return 0;
}

