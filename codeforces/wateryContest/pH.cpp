#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string.h>
#include <cmath>
using namespace std;
typedef pair<int,int> pii;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n, m;
	cin >> n >> m;
	if ( m%n != 0 )	return cout << -1 << '\n', 0;
	long long d = m/n, cnt = 0;
	while ( d%2 == 0 ) {
		cnt++;
		d /= 2;
	}
	while ( d%3 == 0 ) {
		cnt++;
		d /= 3;
	}
	if ( d != 1 )	cout << -1 <<'\n';
	else	cout << cnt << '\n';
	return 0;
}

