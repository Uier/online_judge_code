#include <iostream>
#include <vector>
using namespace std;
vector<int> G[26];
int pt[26];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t, n;
	cin >> t;
	while ( t-- && cin >> n ) {
		string s;
		for ( int i=0; i<n; ++i ) {
			cin >> s;
			G[int(s[0]-'a')].emplace_back(int(s.back()-'a'));
		}
		
	}
	return 0;
}

