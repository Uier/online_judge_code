#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool G[6][6], V[6][6];
vector<string> ans;
string s;
void dfs(int x, int y) {
	if ( y == 9 ) {
		ans.push_back(s);
		return;
	}
	for ( int i=1; i<6; ++i )
		if ( G[x][i] && !V[x][i] ) {
			V[x][i] = V[i][x] = true;
			s.push_back((char)('0'+i));
			dfs(i,y+1);
			s.pop_back();
			V[x][i] = V[i][x] = false;
		}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	G[1][2] = G[1][5] = G[1][3] = true;
	G[2][1] = G[2][5] = G[2][3] = true;
	G[3][1] = G[3][2] = G[3][4] = G[3][5] = true;
	G[4][3] = G[4][5] = true;
	G[5][1] = G[5][2] = G[5][4] = G[5][3] = true;
	s.push_back('1');
	dfs(1,1);
	sort(ans.begin(),ans.end());
	for ( string i : ans )
		cout << i << '\n';
	return 0;
}

