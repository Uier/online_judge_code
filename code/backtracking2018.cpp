#include <iostream>
using namespace std;
int n, s[100];
bool V[100];
void backtracking(int x) {
	if ( x == n ) {
		for ( int i=0; i<n; ++i )	cout << s[i] << ' ';
		cout << '\n';
		return;
	}
	for ( int i=1; i<=n; ++i )
		if ( !V[i] ) {
			s[x] = i;
			V[i] = true;
			backtracking(x+1);
			V[i] = false;
		}
}
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	cin >> n;
	backtracking(0);
	return 0;
}

