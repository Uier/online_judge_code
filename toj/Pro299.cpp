#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
int t, n, a[5010], bit[5010];
int sum(int i) {
	if ( i > 0 )
		return bit[i]+sum(i-(i&-i));
	return 0;
}
void add(int i) {
	if ( i > n )
		return;
	bit[i]++;
	add(i+(i&-i));
}
bool cal(int l, int r) {
    add(a[r]);
    int p = min(a[l],a[r]);
    int q = max(a[l],a[r]);
    if ( q-p+1 == r-l+1 && sum(q)-sum(p-1) == q-p+1 )
    	return true;
    return false;
} 
int main() {
      ios::sync_with_stdio(false);
      cin.tie(0);
    cin >> t;
    while ( t-- ) {
        memset(a,0,sizeof a);
        cin >> n;
        for ( int i=1; i<=n; i++ )
            cin >> a[i];
        int ans = 0;
        for ( int i=1; i<n; i++ ) {
        	memset(bit,0,sizeof bit);
			add(a[i]);
            for ( int j=i+1; j<=n; j++ )
                if ( cal(i,j) )
                    ans++;
		}
        cout << ans << '\n';
    }
    return 0;
}
