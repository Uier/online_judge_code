#include <iostream>
#include <vector>
#define maxn 1000005
using namespace std;
string str[2][maxn];
int fail[maxn];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	string s, t;
	cin >> n;
	for ( int i=0; i<n; ++i )	cin >> str[0][i];
	int cur = 1, pre = 0;
    while ( n > 1 ) {
		for ( int i=0; i<n; i+=2 ) {
			if ( i+1 == n ) {
				str[cur][i>>1] = str[pre][i];
				continue;
			}
			int len = str[pre][i+1].size();
			int j = fail[0] = -1;
			for ( int k=1; k<len; ++k ) {
				while ( j != -1 && str[pre][i+1][k] != str[pre][i+1][j+1] )	j = fail[j];
				if ( str[pre][i+1][k] == str[pre][i+1][j+1] )	j++;
				fail[k] = j;
			}
			int sz = str[pre][i].size(), pos = -1;
			j = -1;
			for ( int k=0; k<sz; ++k ) {
				while ( j != -1 && str[pre][i][k] != str[pre][i+1][j+1] )	j = fail[j];
				if ( str[pre][i][k] == str[pre][i+1][j+1] )	j++;
				if ( k == sz-1 ) {
					pos = j;
				}
			}
			str[cur][i>>1] = str[pre][i];
			if ( pos < 0 )	str[cur][i>>1] += str[pre][i+1];
			else {
				for ( int k=pos+1; k<len; ++k )	str[cur][i>>1].push_back(str[pre][i+1][k]);
			}
		}
		cur ^= 1;
		pre ^= 1;
		n = (n>>1) + (n%2);
    }
    cout << str[pre][0] << '\n';
	// cin >> n >> s;
	// for ( int k=1; k<n; ++k ) {
	// 	cin >> t;
	// 	int len = t.size();
	// 	int j = fail[0] = -1;
	// 	for ( int i=1; i<t.size(); ++i ) {
	// 		while ( j != -1 && t[i] != t[j+1] )	j = fail[j];
	// 		if ( t[i] == t[j+1] )	j++;
	// 		fail[i] = j;
	// 	}
	// 	int sz = s.size(), pos = -1;
	// 	j = -1;
	// 	for ( int i=0; i<sz; ++i ) {
	// 		while ( j != -1 && s[i] != t[j+1] )	j = fail[j];
	// 		if ( s[i] == t[j+1] )	j++;
	// 		if ( i == sz-1 ) {
	// 			pos = j;
	// 		}
	// 	}
	// 	if ( pos < 0 )	s += t;
	// 	else {
	// 		for ( int i=pos+1; i<len; ++i )	s.push_back(t[i]);
	// 	}
	// }
	// cout << s << '\n';
	return 0;
}
/*
hmi i i mi
hmi
hmi imi
hmmi
*/