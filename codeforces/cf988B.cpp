#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(string x, string y) {
	return x.size() < y.size();
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	string s[105];
	cin >> n;
	for ( int i=0; i<n; ++i )
		cin >> s[i];
	sort(s,s+n,cmp);
	bool fail = false;
	for ( int i=0; i<n-1; ++i ) {
		if ( s[i+1].find(s[i]) != string::npos )	continue;
		fail = true;
	}
	if ( fail )	cout <<"NO\n";
	else {
		cout << "YES\n";
		for ( int i=0; i<n; ++i )	cout << s[i] << '\n';
	}
	return 0;
}

