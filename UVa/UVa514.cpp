#include <iostream>
#include <stack>
using namespace std;
int a[1005];
stack<int> s;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, x, blank = 0;
	while ( cin >> n && n ) {
		while ( cin >> a[1] && a[1] ) {
			for ( int i=2; i<=n; ++i)
				cin >> a[i];
			int p = 1, i = 1;
			s.push(p);
			while ( i <= n && p <= n )
				if ( !s.empty() && a[i] == s.top() ) {
					s.pop();
					++i;
				}
				else
					s.push(++p);
			if ( !s.empty() )	cout << "No\n";
			else	cout << "Yes\n";
			while ( !s.empty() )	s.pop();
		}
		cout << '\n'; 
	}
	return 0;
}

