#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <string.h>
#include <map>
#define maxn 1005
using namespace std;
int arr[maxn];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, h;
	cin >> n >> h;
	for ( int i=1; i<=n; ++i ) {
		cin >> arr[i];
	}
	for ( int i=2; i<=n; ++i ) {
		int j = i, cap = h;
		while ( j > 1 && arr[j] > arr[j-1] ) {
			swap(arr[j-1],arr[j]);
			j--;
		}
		for ( int k=1; k+1<=i; k+=2 ) {
			cap -= max(arr[k],arr[k+1]);
		}
		if ( i&1 )	cap -= arr[i];
		if ( cap < 0 ) {
			cout << i-1 << '\n';
			return 0;
		}
	}
	cout << n << '\n';
	return 0;
}

