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
int arr[maxn*2];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for ( int i=1; i<=n; ++i ) {
		cin >> arr[i];
		arr[i+n] = arr[i];
	} 
	int mx = 0, row = 0;
	for ( int i=1; i<=n*2; ++i ) {
		if ( arr[i] == 1 ) {
			row++;
		} else {
			mx = max(mx,row);
			row = 0;
		}
	}
	cout << mx << '\n';
	return 0;
}

