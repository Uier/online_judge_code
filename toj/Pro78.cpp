#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int,int> L;
L a[1000010];
bool cmp(L x, L y) {
    return x.first < y.first;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
	if ( n > 0 ) {
	    for ( int i=0; i<n; i++ )
	        cin >> a[i].first >> a[i].second;
	    sort(a,a+n,cmp);
	    int m=0;
		while ( m < n-1 ) {
			if ( a[m+1].first <= a[m].second ) {
				a[m+1].first = a[m].first;
				a[m+1].second = max(a[m].second,a[m+1].second);
			}
			else
				cout << a[m].first << ' ' << a[m].second << '\n';
			m++;
		}
		cout << a[n-1].first << ' ' << a[n-1].second << '\n';
	}
    return 0;
}

