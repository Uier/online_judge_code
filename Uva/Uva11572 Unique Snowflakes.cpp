#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
queue<int> Q;
bool u[1000000005];
int main()
{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int t, n, ans;
	while ( cin >> t ) {
		if ( t == 0 )
			break;
		while ( t-- ) {
			while ( !Q.empty() )
				Q.pop();
			memset(u, false, sizeof(u));
			cin >> n;
			ans = 0;
			while ( n-- ) {
				int a;
				cin >> a;
				if ( !u[a] )
					Q.push(a);
				else {
					while ( Q.front() != a ) {
						u[Q.front()] = false;
						Q.pop();
					}
					Q.pop();
					Q.push(a);
				}
				u[a] = true;
				ans = max(ans, (int)Q.size());
			}
			cout << ans << '\n';
		}
	}
	return 0;
}

