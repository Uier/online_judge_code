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
	int n, k;
	pii arr[101];
	cin >> n;
	for ( int i=0; i<n; ++i )	cin >> arr[i].first >> arr[i].second;
	cin >> k;
	for ( int i=0; i<n; ++i ) {
		if ( arr[i].first <= k && k <= arr[i].second ) {
			cout << n-i << '\n';
			return 0;
		}
	}
}

