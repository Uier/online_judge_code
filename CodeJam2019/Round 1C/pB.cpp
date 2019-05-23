#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string.h>
#include <cmath>
using namespace std;
typedef pair<int,int> pii;
int main() {
	int t, f;
	cin >> t >> f;
	while ( t-- ) {
		string s[5] = {"", "", "", "", ""};
		char x;
		for ( int i=0; i<4; ++i ) {
			int cnt[5] = {0,0,0,0,0};
			for ( int j=6; j<=591; j+=5 ) {
				cout << j+i << endl;
				cin >> x;
				cnt[x-'A']++;
			}
			for ( int j='A'; j<='E'; ++j )
				if ( cnt[j-'A'] < 120 )
					s[i].push_back(j);
		}
		int prcnt = 0;
		int pr[4] = {0,0,0,0}, pt = 0;
		for ( int i=0; i<4; ++i )
			for ( int j=i+1; j<4; ++j )
				if ( s[i] == s[j] ) {
					cout << i+1 << endl;
					cin >> x;
					if ( x == s[i][0] )	swap(s[i][0],s[i][1]);
					else	swap(s[j][0],s[j][1]);
					pr[pt++] = i;
					pr[pt++] = j;
					prcnt++;
				}
		string ans = "";
		if ( prcnt == 0 ) {
			cout << 1 << endl;
			cin >> x;
			if ( x == s[0][0] )	swap(s[0][0],s[0][1]);
			x = s[0][1];
			for ( int k=0; k<3; ++k ) {
				for ( int i=1; i<4; ++i ) {
					if ( s[i][0] == x ) {
						x = s[i][1];
						break;
					} else if ( s[i][1] == x ) {
						swap(s[i][0],s[i][1]);
						x = s[i][1];
						break;
					}
				}
			}
			for ( int i=0; i<4; ++i )	ans.push_back(s[i][0]);
			ans.push_back(x);
		} else if ( prcnt == 1 ) {
			cout << pr[0]+1 << endl;
			cin >> x;
			if ( x == s[pr[0]][0] )	swap(s[pr[0]][0],s[pr[0]][1]);
			else	swap(s[pr[1]][0],s[pr[1]][1]);
			int idx = 0;
			for ( int i=0; i<4; ++i ) {
				if ( i != pr[0] && i != pr[1] ) {
					idx = i;
					break;
				}
			}
			cout << idx+1 << endl;
			cin >> x;
			if ( x == s[idx][0] )	swap(s[idx][0],s[idx][1]);
			x = s[idx][1];
			for ( int i=0; i<4; ++i ) {
				if ( i != pr[0] && i != pr[1] && i != idx ) {
					idx = i;
					break;
				}
			}
			if ( x == s[idx][0] )	swap(s[idx][0],s[idx][1]);
			x = s[idx][1];
			for ( int i=0; i<4; ++i )	ans.push_back(s[i][0]);
			ans.push_back(x);
		} else if ( prcnt == 2 ) {
			bool _[5] = {0,0,0,0,0};
			for ( int i=0; i<4; ++i )	_[s[i][0]-'A'] = 1;
			for ( int i=0; i<5; ++i )	if ( !_[i] )	s[4].push_back('A'+i);
			for ( int i=0; i<5; ++i )	ans.push_back(s[i][0]);
		}
		cout << ans << endl;
		cin >> x;
	}
	
	return 0;
}

