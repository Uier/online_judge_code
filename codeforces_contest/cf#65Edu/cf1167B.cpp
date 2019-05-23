#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string.h>
#include <cmath>
using namespace std;
typedef pair<int,int> pii;
int mul[7][7];
pii f(int x) {
	for ( int i=1; i<=6; ++i )
		for ( int j=i+1; j<=6; ++j )
			if ( mul[i][j] == x )
				return pii{i,j};
}
int main() {
	int arr[] = {0, 4, 8, 15, 16, 23, 42};
	int ans[7];
	for ( int i=1; i<=6; ++i )
		for ( int j=i+1; j<=6; ++j )
			mul[i][j] = arr[i]*arr[j];
	int x, y;
	cout << "? 1 2\n";
	fflush(stdout);
	cin >> x;
	cout << "? 2 3\n";
	fflush(stdout);
	cin >> y;
	pii t1 = f(x), t2 = f(y);
	if ( t1.first == t2.first ) {
		ans[1] = t1.second;
		ans[2] = t1.first;
		ans[3] = t2.second;
	} else if ( t1.first == t2.second ) {
		ans[1] = t1.second;
		ans[2] = t1.first;
		ans[3] = t2.first;
	} else if ( t1.second == t2.first ) {
		ans[1] = t1.first;
		ans[2] = t1.second;
		ans[3] = t2.second;
	} else {
		ans[1] = t1.first;
		ans[2] = t1.second;
		ans[3] = t2.first;
	}
	cout << "? 4 5\n";
	fflush(stdout);
	cin >> x;
	cout << "? 5 6\n";
	fflush(stdout);
	cin >> y;
	t1 = f(x);
	t2 = f(y);
	if ( t1.first == t2.first ) {
		ans[4] = t1.second;
		ans[5] = t1.first;
		ans[6] = t2.second;
	} else if ( t1.first == t2.second ) {
		ans[4] = t1.second;
		ans[5] = t1.first;
		ans[6] = t2.first;
	} else if ( t1.second == t2.first ) {
		ans[4] = t1.first;
		ans[5] = t1.second;
		ans[6] = t2.second;
	} else {
		ans[4] = t1.first;
		ans[5] = t1.second;
		ans[6] = t2.first;
	}
	cout << '!';
	for ( int i=1; i<=6; ++i )	cout << ' ' << arr[ans[i]];
	cout << '\n';
	fflush(stdout);
	return 0;
}

