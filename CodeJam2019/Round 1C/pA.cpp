#include <iostream>
#include <string.h>
#define maxn 256
using namespace std;
string arr[maxn];
bool ign[maxn];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t, n, cs = 1;
	cin >> t;
	while ( t-- && cin >> n ) {
		cout << "Case #" << cs++ << ": ";
		int mx_len = 0;
		for ( int i=0; i<n; ++i ) {
			cin >> arr[i];
			mx_len = max((int)arr[i].size(), mx_len);
		}
		mx_len *= 2;
		memset(ign, 0, sizeof(ign));
		for ( int i=0; i<n; ++i )
			while ( arr[i].size() < mx_len )
				arr[i] += arr[i];
		bool win = 0;
		string ans = "";
		for ( int i=0; i<mx_len; ++i ) {
			bool R = 0, P = 0, S = 0;
			for ( int j=0; j<n; ++j ) {
				if ( ign[j] )	continue;
				if ( arr[j][i] == 'R' )	R = 1;
				else if ( arr[j][i] == 'P' )	P = 1;
				else	S = 1;
			}
			if ( R && P && S ) {
				break;
			} else if ( R && P ) {
				ans.push_back('P');
				for ( int j=0; j<n; ++j )	if ( arr[j][i] == 'R' )	ign[j] = 1;
			} else if ( P && S ) {
				ans.push_back('S');
				for ( int j=0; j<n; ++j )	if ( arr[j][i] == 'P' )	ign[j] = 1;
			} else if ( R && S ) {
				ans.push_back('R');
				for ( int j=0; j<n; ++j )	if ( arr[j][i] == 'S' )	ign[j] = 1;
			} else if ( R ) {
				ans.push_back('P');
				for ( int j=0; j<n; ++j )	if ( arr[j][i] == 'R' )	ign[j] = 1;
				win = 1;
				break;
			} else if ( P ) {
				ans.push_back('S');
				for ( int j=0; j<n; ++j )	if ( arr[j][i] == 'P' )	ign[j] = 1;
				win = 1;
				break;
			} else {
				ans.push_back('R');
				for ( int j=0; j<n; ++j )	if ( arr[j][i] == 'S' )	ign[j] = 1;
				win = 1;
				break;
			}
		}
		if ( win )	cout << ans << '\n';
		else	cout << "IMPOSSIBLE\n";
	}
	return 0;
}

