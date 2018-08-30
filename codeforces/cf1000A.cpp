#include <iostream>
using namespace std;
string s1[105];
bool V[105];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, ans = 0;
	string t;
	cin >> n;
	for ( int i=0; i<n; ++i )	cin >> s1[i];
	for ( int i=0; i<n; ++i ) {
		cin >> t;
		bool flag = false;
		for ( int j=0; j<n; ++j ) {
			if ( V[j] )	continue;
			if ( s1[j] == t ) {
				V[j] = true;
				flag = true;
				break;
			}
		}
		if ( !flag ) {
			ans++;
		}
	}
	cout << ans << '\n';
	return 0;
}

