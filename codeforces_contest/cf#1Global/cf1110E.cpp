#include <iostream>
#define maxn 100005
using namespace std;
int c[maxn], t[maxn];
bool d[maxn];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for ( int i=0; i<n; ++i )	cin >> c[i];
	for ( int i=0; i<n; ++i ) {
		cin >> t[i];
		if ( c[i] != t[i] )	d[i] = true;
	}
	if ( d[0] || d[n-1] )
		return cout << "No\n", 0;
	for ( int i=1; i<n-1; ++i ) {
		while ( d[i] ) {
			
			++i;
		}
	}
	return 0;
}

