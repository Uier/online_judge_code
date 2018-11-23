#include <iostream>
using namespace std;
int vis[605];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, cnt = 0, x;
	cin >> n;
	for ( int i=0; i<n; ++i ) {
		cin >> x;
		if ( x != 0 && !vis[x] ) {
			vis[x] = 1;	
			cnt++;
		}
	}
	cout << cnt <<'\n';
	return 0;
}

