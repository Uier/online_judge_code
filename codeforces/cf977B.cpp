#include <iostream>
using namespace std;
int cnt[105];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	string s;
	cin >> n >> s;	
	for ( int i=1; i<n; ++i ) {
		for ( int j=1; j<n; ++j ) {
			if ( s[i-1] == s[j-1] && s[i] == s[j] )	cnt[i]++;
		}
	}
	int ind = 0, max = 0;
	for ( int i=1; i<n; ++i ) {
		if ( cnt[i] > max ) {
			max = cnt[i];
			ind = i;
		}
	}
	cout << s[ind-1] << s[ind] << '\n';
		
	return 0;
}

