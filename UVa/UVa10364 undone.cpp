#include <iostream>
#include <algorithm>
using namespace std;
int t, n, a[25], sum, v[25], c = 1;
bool backtracking(int x, int len, int edge) {
	if ( len == sum/4 )	 {
		len = 0;
		edge++;
		if ( edge == 3 )	return true;
	}
	for ( int i=x+1; i<n; ++i )
		if ( v[i] != c && len+a[i] <= sum/4 ) {
			v[i] = c;
			return backtracking(i,len+a[i],edge);
			v[i] = c-1;
		}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while ( t-- && cin >> n && c++ ) {
		sum = 0;
		for ( int i=0; i<n; ++i ) {
			cin >> a[i];
			sum += a[i];
		}
		sort(a,a+n);
		for ( int i=0; i<n/2; ++i )	swap(a[i],a[n-1-i]);
		if ( sum%4 != 0 || a[0] > sum/4 )	cout << "no\n";
		else	cout << (backtracking(0,0,0) ? "yes\n" : "no\n");
	}
	return 0;
}

