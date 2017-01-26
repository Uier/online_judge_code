#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while ( t-- ) {
		string s;
		cin >> s;
		int ans=0;
		for ( int i=0; i<s.size(); i++ )
			if ( s[i] == 'y' )
				for ( int j=i+1; j<s.size(); j++ )
					if ( s[j] == 'r' && (j+1)%(i+1) == 0 && 
						(j+1)*((j+1)/(i+1))-1 < s.size() &&
						s[(j+1)*((j+1)/(i+1))-1] == 'x' )
						ans++;
		cout << ans << '\n';
	}
	return 0;
}

