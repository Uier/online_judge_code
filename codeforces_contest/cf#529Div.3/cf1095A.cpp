#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, cnt = 1;
	string s, t = "";
	cin >> n >> s;
	for ( int i=0; i<n; i+=cnt, ++cnt ) {
		t.push_back(s[i]);
	}
	cout << t << '\n';
	return 0;
}


