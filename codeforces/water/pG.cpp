#include <iostream>
#include <map>
using namespace std;
map<char,int> M;
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int n, ans = 0, tmp = 0;
	string s;
	cin >> n >> s;
	for ( int i=0; i<n; ++i ) {
		if ( s[i] <= 'Z' ) {
			tmp = 0;
			M.clear();
		} else {
			if ( M[s[i]] == 0 ) {
				M[s[i]]++;
				tmp++;
			}
		}
		ans = max(ans,tmp);
	}
	cout << ans << '\n';
	return 0;
}

