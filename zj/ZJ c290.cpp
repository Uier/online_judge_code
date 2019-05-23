#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	int a[] = {0,0};
	for ( int i=0; i<s.size(); ++i )	a[i&1] += s[i]-'0';
	cout << (a[0]>a[1] ? a[0]-a[1] : a[1]-a[0]) << '\n';
	return 0;
}

