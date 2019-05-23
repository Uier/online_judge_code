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
	int a;
	char x;
	cin >> a;
	int arr[a][a];
	for ( int i=0; i<a; ++i )	for ( int j=0; j<a; ++j ) {
		cin >> x;
		if ( x == '#' )	arr[i][j] = 1;
		else if ( x == '.' )	arr[i][j] = 0;
	}
	for ( int i=0; i<a; ++i )	for ( int j=0; j<a; ++j ) {
		if ( arr[i][j] == 0 ) {
			if ( j == 0 || j == a-1 || arr[i+1][j-1] == 1 || arr[i+1][j] == 1 || arr[i+1][j+1] == 1 || arr[i+2][j] == 1 ) {
				cout << "NO";
				return 0;
			}
		} else {
			arr[i][j] = 1;
			arr[i+1][j-1] = 1;
			arr[i+1][j] = 1;
			arr[i+1][j+1] = 1;
			arr[i+2][j] = 1;
		}
	}
	cout << "YES";
	return 0;
}

