#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	string s;
	cin >> t;
	while ( t-- && cin >> s ) {
		int a[3] = {0,0,0}, len = s.size();
		for ( int i=0; i<len; ++i ) {
			if ( s[i] >= 'a' && s[i] <= 'z' ) {
				a[0]++;
			} else if ( s[i] >= 'A' && s[i] <= 'Z' ) {
				a[1]++;
			} else {
				a[2]++;
			}
		}
		if ( a[0] && a[1] && a[2] ) {
			
		} else if ( a[0] && a[1] ) {
			for ( int i=0; i<len; ++i ) {
				if ( a[0] > 1 && s[i] >= 'a' && s[i] <= 'z' ) {
					s[i] = '1';
					break;
				}
				if ( a[1] > 1 && s[i] >= 'A' && s[i] <= 'Z' ) {
					s[i] = '1';
					break;
				}
			}
		} else if ( a[1] && a[2] ) {
			for ( int i=0; i<len; ++i ) {
				if ( a[1] > 1 && s[i] >= 'A' && s[i] <= 'Z' ) {
					s[i] = 'a';
					break;
				}
				if ( a[2] > 1 && s[i] >= '0' && s[i] <= '9' ) {
					s[i] = 'a';
					break;
				}
			}
		} else if ( a[0] && a[2] ) {
			for ( int i=0; i<len; ++i ) {
				if ( a[0] > 1 && s[i] >= 'a' && s[i] <= 'z' ) {
					s[i] = 'A';
					break;
				}
				if ( a[2] > 1 && s[i] >= '0' && s[i] <= '9' ) {
					s[i] = 'A';
					break;
				}
			}
		} else {
			if ( a[0] ) {
				for ( int i=0; i<len-1; ++i ) {
					if ( s[i] >= 'a' && s[i] <= 'z' && s[i+1] >= 'a' && s[i+1] <= 'z' ) {
						s[i] = 'A';
						s[i+1] = '1';
						break;
					}
				}
			} else if ( a[1] ) {
				for ( int i=0; i<len-1; ++i ) {
					if ( s[i] >= 'A' && s[i] <= 'Z' && s[i+1] >= 'A' && s[i+1] <= 'Z' ) {
						s[i] = 'a';
						s[i+1] = '1';
						break;
					}
				}
			} else {
				for ( int i=0; i<len-1; ++i ) {
					if ( s[i] >= '0' && s[i] <= '9' && s[i+1] >= '0' && s[i+1] <= '9' ) {
						s[i] = 'a';
						s[i+1] = 'A';
						break;
					}
				}
			}
		}
		cout << s << '\n';
	}
	return 0;
}

