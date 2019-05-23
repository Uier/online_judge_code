#include <iostream>
#include <queue>
#include <vector>
#define maxn 2005
using namespace std;
typedef pair<int,int> pii;
string s[maxn];
int n, m, mp[maxn], in[maxn], ansn[maxn], ansm[maxn];
bool vis[maxn], E[maxn][maxn];
queue<pii> Q;
vector<int> G[maxn];
void dfs(int x, int idx) {
	mp[x] = idx;
	for ( int i : G[x] )
		if ( !mp[i] )
			dfs(i,idx);
}
int main() {
	ios::sync_with_stdio(false);
	//   sync_with_YinHsuan(true);
	cin.tie(0);
	cin >> n >> m;
	for ( int i=0; i<n; ++i ) {
		cin >> s[i];
		for ( int j=0; j<m; ++j ) {
			if ( s[i][j] == '=' ) {
				G[i].emplace_back(n+j);
				G[n+j].emplace_back(i);
			}
		}
	}
	int cnt = 1;
	for ( int i=0; i<n+m; ++i )
		if ( !mp[i] ) {
			dfs(i,cnt);
			cnt++;
		}
//	for ( int i=0; i<n+m; ++i ) {
//		if ( i < n ) {
//			cout << i << ' ' << mp[i] << '\n';
//		} else {
//			cout << i-n << ' ' << mp[i] << '\n';
//		}
//	}
	for ( int i=0; i<n+m; ++i )	G[i].clear();
	for ( int i=0; i<n; ++i )
		for ( int j=0; j<m; ++j )
			if ( s[i][j] == '<' ) {
				if ( mp[i] == mp[n+j] || E[mp[n+j]][mp[i]] )	return cout << "No\n", 0;
				G[mp[i]].emplace_back(mp[n+j]);
				E[mp[i]][mp[n+j]] = 1;
				in[mp[n+j]]++;
			} else if ( s[i][j] == '>' ) {
				if ( mp[i] == mp[n+j] || E[mp[i]][mp[n+j]] )	return cout << "No\n", 0;
				G[mp[n+j]].emplace_back(mp[i]);
				E[mp[n+j]][mp[i]] = 1;
				in[mp[i]]++;
			}
	for ( int i=1; i<cnt; ++i )
		if ( !in[i] ) {
			vis[i] = 1;
			Q.push(pii{i,1});
		}
	while ( !Q.empty() ) {
		pii tmp = Q.front();	Q.pop();
		int x = tmp.first;
		int y = tmp.second;
		for ( int i=0; i<n+m; ++i )
			if ( mp[i] == x ) {
			if ( i < n ) {
				if ( ansn[i] != 0 )	return cout << "No\n", 0;
				ansn[i] = y;
			}
			else {
				if ( ansm[i-n] != 0 )	return cout << "No\n", 0;
				ansm[i-n] = y;
			}
		}
		for ( int i : G[x] )
			in[i]--;
		for ( int i=1; i<cnt; ++i )
			if ( !vis[i] && !in[i] ) {
				vis[i] = 1;
				Q.push(pii{i,y+1});
			}
	}
	for ( int i=0; i<n; ++i )	if ( ansn[i] == 0 )	return cout << "No\n", 0;
	for ( int i=0; i<m; ++i )	if ( ansm[i] == 0 )	return cout << "No\n", 0;
	cout << "Yes\n";
	for ( int i=0; i<n; ++i )	cout << ansn[i] << ' ';
	cout << '\n';
	for ( int i=0; i<m; ++i )	cout << ansm[i] << ' ';
	cout << '\n';
	return 0;
}

