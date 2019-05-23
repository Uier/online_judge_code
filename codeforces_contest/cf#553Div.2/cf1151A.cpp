#include <iostream>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
using namespace std;
int cnt(string s) {
	int a = 0;
	a += min(abs(s[0]-'A'),26-abs(s[0]-'A'));
	a += min(abs(s[1]-'C'),26-abs(s[1]-'C'));
	a += min(abs(s[2]-'T'),26-abs(s[2]-'T'));
	a += min(abs(s[3]-'G'),26-abs(s[3]-'G'));
	return a;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	string s;
	cin >> n >> s;
	int len = s.size(), ans = -1;
	for ( int i=3; i<len; ++i ) {
		string tmp = "";
		for ( int j=i-3; j<=i; ++j )	tmp.push_back(s[j]);
		int res = cnt(tmp);
		if ( ans == -1 || res < ans )	ans = res;
	}
	cout << ans << '\n';
	return 0;
}

