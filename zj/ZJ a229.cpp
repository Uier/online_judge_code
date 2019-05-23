#include <iostream>
#include <vector>
using namespace std;
int n;
string tmp;
vector<string> ans;
void dfs(int x, int l, int r) {
	if ( x == 2*n ) {
		ans.emplace_back(tmp);
		return;
	}
	if ( l < n ) {
		tmp.push_back('(');
		dfs(x+1,l+1,r);
		tmp.pop_back();
	}
	if ( l > r ) {
		tmp.push_back(')');
		dfs(x+1,l,r+1);
		tmp.pop_back();
	}
}
int main() {
	ios::sync_with_stdio(false);
	//   sync_with_YinHsuan(true);
	cin.tie(0);
	bool f = 1;
	while ( cin >> n ) {
		if ( !f )	cout << '\n';
		f = 0;
		dfs(0,0,0);
		for ( string i : ans )
			cout << i << '\n';
		ans.clear();
	}
	return 0;
}

