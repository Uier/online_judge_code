#include <iostream>
using namespace std;
int n, cnt[3];
string s;
void rep(int x, char a, char b) {
	if ( x < 1 )	return;
	if ( a < b ) {
		for ( int i=0; i<n; ++i )
			if ( s[i] == b ) {
				s[i] = a;
				if ( --x == 0 )	return;
			}
	}
	else {
		for ( int i=n-1; i>=0; --i )
			if ( s[i] == b ) {
				s[i] = a;
				if ( --x == 0 )	return;
			}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> s;
	for ( int i=0; i<n; ++i )	cnt[s[i]-'0']++;
	if ( cnt[0] == cnt[1] && cnt[1] == cnt[2] )	return cout << s << '\n', 0;
	int lack = 0;
	if ( cnt[0] < n/3 ) {
		if ( cnt[1] < n/3 ) { //    	001 
			rep(n/3-cnt[0],'0','2');
			rep(n/3-cnt[1],'1','2');
		} else if ( cnt[2] < n/3 ) { //	010
			rep(n/3-cnt[0],'0','1');
			rep(n/3-cnt[2],'2','1');
		} else { // 					011
			rep(cnt[1]-n/3,'0','1');
			rep(cnt[2]-n/3,'0','2');
		}
	} else {
		if ( !(cnt[1] < n/3) ) { // 	110
			rep(cnt[0]-n/3,'2','0'); 
			rep(cnt[1]-n/3,'2','1');			
		} else if ( cnt[2] < n/3 ) { // 100
			rep(n/3-cnt[2],'2','0');			
			rep(n/3-cnt[1],'1','0');			
		} else { // 					101
			rep(cnt[0]-n/3,'1','0');			
			rep(cnt[2]-n/3,'1','2');			
		}
	}
	cout << s << '\n';
	return 0;
}
