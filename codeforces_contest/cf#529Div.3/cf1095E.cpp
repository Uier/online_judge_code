#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
typedef pair<char,int> pci;
stack<pci> stk;
stack<char> stk2;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	string s;
	cin >> n >> s;
	if ( n&1 )	return cout << 0 << '\n', 0;
	for ( int i=0; i<n; ++i )
		if ( s[i] == '(' )	stk.push(pci{s[i],i+1});
		else
			if ( !stk.empty() && stk.top().first == '(' )	stk.pop();
			else	stk.push(pci{s[i],i+1});
	if ( stk.size() == 2 ) {
		pci y = stk.top();	stk.pop();
		pci x = stk.top();	stk.pop();
		if ( x.first == y.first ) {
			int ans = 0;
			if ( x.first == ')' ) {
				reverse(s.begin(),s.end());
				int cnt = 0;
				for ( int i=0; i<n; ++i ) {
					if ( s[i] == ')' ) {
						if ( cnt
						cnt++;
					}
					else
						if ( !stk2.empty() && stk2.top() == ')' )	stk2.pop();
					ans = max(ans,(int)stk2.size());
				}
			} else {
				for ( int i=0; i<n; ++i ) {
					if ( s[i] == '(' )	stk2.push(s[i]);
					else
						if ( !stk2.empty() && stk2.top() == '(' )	stk2.pop();
					ans = max(ans,(int)stk2.size());
				}
			}
			cout << ans-1 << '\n';
		} else	cout << 0 << '\n';
	} else	cout << 0 << '\n';
	return 0;
}

