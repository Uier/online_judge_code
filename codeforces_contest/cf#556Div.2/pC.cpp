#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string.h>
#include <cmath>
#define maxn 200005
using namespace std;
typedef pair<int,int> pii;
int cnt[3], arr[maxn];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for ( int i=0; i<n; ++i ) {
		cin >> arr[i];
		cnt[arr[i]]++;
	}
	if ( cnt[1] ) {
		if ( cnt[2] ) {
			cout << 2 << ' ' << 1 << ' ';
			cnt[2]--;
			cnt[1]--;
			for ( int i=0; i<cnt[2]; ++i )	cout << 2 << ' ';
			for ( int i=0; i<cnt[1]; ++i )	cout << 1 << ' ';
		} else {
			for ( int i=0; i<n; ++i )	cout << arr[i] << ' ';
		}
	} else {
		for ( int i=0; i<n; ++i )	cout << arr[i] << ' ';
	}
	return 0;
}

