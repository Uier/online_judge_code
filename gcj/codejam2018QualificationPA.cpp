#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T, D, Tcase = 0;
	string s;
	cin >> T;
	while ( T-- && cin >> D ) {
		int cnt = 0;
		cout << "Case #" << ++Tcase << ": ";
		cin >> s;
		int damage = 1, output = 0;
		for ( int i=0; i<s.size(); ++i )
			if ( s[i] == 'C' )	damage <<= 1;
			else	output += damage;
		if ( output <= D )	cout << 0 << '\n';
		else {
			while ( output > D ) {
				cnt++;
				for ( int i=s.size()-1; i>0; --i )
					if ( s[i] == 'S' && s[i-1] == 'C' ) {
						swap(s[i],s[i-1]);
						break;
					}
				int newdamage = 1, newoutput = 0;
				for ( int i=0; i<s.size(); ++i )
					if ( s[i] == 'C' )	newdamage <<= 1;
					else	newoutput += newdamage;
				if ( newoutput == output ) {
					cout << "IMPOSSIBLE\n";
					break;
				}
				output = newoutput;
			}
			if ( output <= D )
				cout << cnt << '\n';
		}
	}
	return 0;
}

