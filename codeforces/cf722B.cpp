#include <iostream>
using namespace std;
int a[105];
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int n;
	string s;
	cin >> n;
	bool ansans=true;
	for ( int i=0; i<n; i++ )
		cin >> a[i];
	getline(cin,s);
	for ( int j=0; j<n; j++ ) {
		getline(cin,s);
		int ans=0;
		bool word = true;
		for ( int i=0; i<s.size(); i++ )
			if ( s[i] == 'a' || s[i] == 'e' || s[i] == 'i' ||
				s[i] == 'o' || s[i] == 'u' || s[i] == 'y' )
				ans++;
		if ( a[j] != ans )
			ansans = false;
	}
	if ( ansans )
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}

