#include <iostream>
#include <string.h>
using namespace std;
int t1[51], t2[51], t3[51];
string s[51];
int type(char x) {
	if ( x == '#' || x == '*' || x == '&' )
		return 1;
	if ( '0' <= x && x >= '9' )
		return 2;
	return 3;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for ( int i=0; i<51; i++ )
		t1[i] = t2[i] = t3[i] = 100;
	for ( int i=0; i<n; i++ ) {
		cin >> s[i];
		if ( type(s[i][0]) == 1 ) {
			t1[i] = 0;
			for ( int j=1; j<s[i].size(); j++ ) {
				if ( type(s[i][j]) == 2 || type(s[i][s[i].size()-j]) == 2 )	t2[i] = min(t2[i],j);
				if ( type(s[i][j]) == 3 || type(s[i][s[i].size()-j]) == 3 )	t3[i] = min(t3[i],j);
			}
		}
		else if ( type(s[i][0]) == 2 ) {
			t2[i] = 0;
			for ( int j=1; j<s[i].size(); j++ ) {
				if ( type(s[i][j]) == 1 || type(s[i][s[i].size()-j]) == 1 )	t1[i] = min(t1[i],j);
				if ( type(s[i][j]) == 3 || type(s[i][s[i].size()-j]) == 3 )	t3[i] = min(t3[i],j);
			}
		}
		else {
			t3[i] = 0;
			for ( int j=1; j<s[i].size(); j++ ) {
				if ( type(s[i][j]) == 1 || type(s[i][s[i].size()-j]) == 1 )	t1[i] = min(t1[i],j);
				if ( type(s[i][j]) == 2 || type(s[i][s[i].size()-j]) == 2 )	t2[i] = min(t2[i],j);
			}
		}
	}
	int ans = 2e9;
	for ( int i=0; i<n; i++ ) {
		for ( int j=i+1; j<n; j++ ) {
			for ( int k=j+1; k<n; k++ ) {
				ans = min(ans,min(t1[i]+t2[j]+t3[k],t1[i]+t3[j]+t2[k]));
				ans = min(ans,min(t2[i]+t1[j]+t3[k],t2[j]+t3[j]+t1[k]));
				ans = min(ans,min(t3[i]+t1[j]+t2[k],t3[i]+t2[j]+t1[k]));
			}
		}
	}
	cout << ans << '\n';
	return 0;
}

