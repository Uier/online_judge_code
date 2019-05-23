#include <iostream>
using namespace std;
int arr[105];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s[2];
	cin >> s[0] >> s[1];
	int n = s[0].size(), ans = 0;
	for ( int i=0; i<n; ++i )	arr[i] = (s[0][i]=='0')+(s[1][i]=='0');
	for ( int i=0; i<n; ++i ) {
		if ( arr[i] == 1 ) {
			if ( i+1 < n && arr[i+1] == 2 ) {
				ans++;
				i++;
			}
		} else if ( arr[i] == 2 ) {
			if ( i+1 < n && arr[i+1] == 2 && i+2 < n && arr[i+2] == 2 ) {
				ans += 2;
				i += 2;
			}
			else if ( i+1 < n && arr[i+1] >= 1 ) {
				ans++;
				i++;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}

