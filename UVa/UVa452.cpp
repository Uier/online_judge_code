#include <iostream>
#include <vector>
#include <queue> 
#include <sstream>
using namespace std;
int cost[26], ans[26];
bool inedge[26];
vector<int> G[26], f;
void dfs(int x, int cur) {
	ans[x] = max(ans[x],cur+cost[x]);
	for ( int i : G[x] )
		dfs(i,ans[x]);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	string s;
	cin >> t;
	getline(cin,s);
	getline(cin,s);
	while ( t-- ) {
		char x;
		int y, st;
		string z;
		f.clear();
		for ( int i=0; i<26; ++i ) {
			G[i].clear();
			cost[i] = inedge[i] = ans[i] = 0;
		}
		while ( getline(cin,s) && s != "" ) {
			stringstream ss(s);
			ss >> x >> y >> z;
			cost[x-'A'] = y;
			inedge[x-'A'] = z.size();
			f.emplace_back(x-'A');
			for ( int i=0; i<z.size(); ++i )
				G[z[i]-'A'].emplace_back(x-'A');
		}
		for ( int i : f )
			if ( !inedge[i] )
				dfs(i,0);
		int theans = 0;
		for ( int i : f )
			theans = max(theans,ans[i]);
		cout << theans << '\n';
		if ( t )	cout << '\n';
	}
	return 0;
}

