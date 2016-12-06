#include <iostream>
using namespace std;
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	string s;
	cin >> s;
	int ans=0;
	ans += min(26-(s[0]-'a'),s[0]-'a');
	for (int i=1; i<s.size(); i++) {
		if ( s[i] > s[i-1] )
			ans += min(26-(s[i]-s[i-1]),s[i]-s[i-1]);
		else
			ans += min(26-(s[i-1]-s[i]),s[i-1]-s[i]);
	}
	cout << ans << '\n';
	return 0;
}

