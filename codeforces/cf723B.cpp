#include <iostream>
#include <stack>
using namespace std;
stack<char> ppap;
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int n, ans=0, amax=0, x=0;
	bool in=false, pin=false, pa=false;
	while ( !ppap.empty() )
		ppap.pop();
	string s;
	cin >> n >> s;
	for ( int i=0; i<s.size(); i++ ) {
		if ( s[i] == '(' ) {
			pa = 1;
			ppap.push(s[i]);
		}
		else if ( s[i] == ')' ) {
			ppap.pop();
			if ( ppap.empty() )
				pa = 0;
			if ( pin )
				ans++;
			pin = false;
		}
		else if ( (s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') ) {
			if ( pa == 1 )
				pin = true;
			else if ( !in ) {
				in = true;
				x = 1;
			}
			else
				x++;
		}
		else {
			if ( pa && pin ) {
				ans++;
				pin = false;	
			}
			else if ( in ) {
				in = false;
				amax = max(amax,x);
				x = 0;
			}
		}
		if ( i == s.size()-1 && in )
			amax = max(amax,x);
	}
	cout << amax << ' ' << ans << '\n';
	return 0;
}

