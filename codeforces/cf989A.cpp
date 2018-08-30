#include <iostream>
using namespace std;
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	string s;
	cin >> s;
	int n = s.size();
	bool flag = false;
	for ( int i=1; i<n-1; ++i ) {
		if ( s[i-1] == '.' || s[i] == '.' || s[i+1] == '.' )
			continue;
		if ( s[i-1] != s[i] && s[i] != s[i+1] && s[i-1] != s[i+1] )
			flag = true;
	}
	cout << (flag ? "Yes\n" : "No\n");
	return 0;
}

