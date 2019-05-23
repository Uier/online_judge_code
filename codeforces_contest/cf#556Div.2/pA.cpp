#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string.h>
#include <cmath>
using namespace std;
typedef pair<int,int> pii;
int arr[50], brr[50];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, r, x;
	cin >> n >> m >> r;
	for ( int i=0; i<n; ++i )	cin >> arr[i];
	for ( int i=0; i<m; ++i )	cin >> brr[i]; 
	int mx = 0;
	for ( int i=0; i<n; ++i ) {
		for ( int j=0; j<m; ++j ) {
			if ( arr[i] <= r && brr[j]-arr[i] > mx ) {
				mx = brr[j]-arr[i];
				x = arr[i];
			}
		}
	}
	if ( mx <= 0 )	cout << r << '\n';
	else	cout << (r/x)*mx+r << '\n';
	return 0;
}

