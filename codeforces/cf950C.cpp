#include <iostream>
#include <vector>
#include <algorithm>
#define mx 200003
using namespace std;
vector<int> sol[mx];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int cnt = 0, pt = 0;
	string s;
	cin >> s;
	for ( int i=0; i<s.size(); ++i ) {
		if ( s[i] == '0' )	sol[pt++].emplace_back(i+1);
		else {
			if ( pt == 0 ) {
				cout << -1 << '\n';	return 0;
			}
			sol[--pt].emplace_back(i+1);
		}
		cnt = max(cnt,pt);
	}
	if ( cnt != pt ) {
		cout << -1 << '\n';	return 0;
	} else {
		cout << cnt << '\n';
		for ( int i=0; i<cnt; ++i ) {
			cout << sol[i].size();
			for ( int j : sol[i] )
				cout << ' ' << j;
			cout << '\n';
		}
	}
	return 0;
}

