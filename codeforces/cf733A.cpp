#include <iostream>
using namespace std;
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	string s;
	cin >> s;
	int i=0, now=-1, ans=0;
	while ( i < s.size() ) {
		if ( s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O'
			|| s[i] == 'U' || s[i] == 'Y' ) {
			ans = max(ans,i-now);
			now = i;
		}
		i++;
	}
	ans = max(ans,i-now);
	cout << ans << '\n';
	return 0;
}

