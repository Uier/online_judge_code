#include <iostream>
#include <algorithm>
#include <unordered_map>
#define int long long
using namespace std;
int t, d, len, cnt, arr[10];
string s;
bool V[10];
unordered_map<string,bool> M;
void rec() {
	int tmp = 0;
	for ( int i=0; i<len; ++i )	tmp = tmp*10+arr[i];
	if ( tmp%d == 0 )	cnt++;
}
void dfs(int x) {
	if ( x == len ) {
		rec();
		return;
	}
	char pre = ' ';
	for ( int i=0; i<len; ++i )
		if ( !V[i] ) {
			if ( s[i] == pre )	continue;
			V[i] = 1;
			arr[x] = s[i]-'0';
			pre = s[i];
			dfs(x+1);
			V[i] = 0;
		}
}
main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while ( t-- && cin >> s >> d ) {
		M.clear();
		len = s.size();
		cnt = 0;
		sort(s.begin(),s.end());
		dfs(0);
		cout << cnt << '\n';
	}
	return 0;
}

