#include <iostream>
#include <string.h>
#define maxn 1000005
using namespace std;
int arr[maxn];
bool fail[maxn];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t, n;
	cin >> t;
	while ( t-- && cin >> n ) {
		for ( int i=0; i<n; ++i )	cin >> arr[i];
		memset(fail,0,sizeof(fail));
		int cur_mx = arr[0], cur_mn = arr[n-1], ans = 0;
		for ( int i=1; i<n-1; ++i )
			if ( arr[i] > cur_mx )	cur_mx = arr[i];
			else	fail[i] = 1;
		for ( int i=n-2; i>0; --i ) {
			if ( arr[i] < cur_mn ) {
				cur_mn = arr[i];
				if ( !fail[i] )	ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

