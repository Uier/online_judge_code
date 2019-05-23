#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string.h>
#include <cmath>
#define int long long
using namespace std;
typedef pair<int,int> pii;
int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, a, b;
	cin >> n >> a >> b;
	for ( int i=0; i<=n; ++i ) {
		if ( n >= a*i && (n-a*i)%b == 0 ) {
			cout << "YES\n";
			cout << i << ' ' << (n-a*i)/b << '\n';
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}

