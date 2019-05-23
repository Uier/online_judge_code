#include <iostream>
#include <algorithm>
using namespace std;
struct meow {
	int p, r;
} arr[1005];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, n;
    cin >> t;
    while ( t-- && cin >> n ) {
        for ( int i=0; i<n; ++i )	cin >> arr[i].p >> arr[i].r;
        sort(arr,arr+n,[](meow x, meow y){return x.p > y.p;});
        long long pdt = arr[0].p, ans = arr[0].r;
        for ( int i=1; i<n; ++i ) {
            while ( ans % arr[i].p != arr[i].r && pdt != 0 )    ans += pdt;
            pdt *= arr[i].p;
            if ( ans >= 955049953 )    break;
        }
        if ( ans >= 955049953 )    cout << -1 << '\n';
        else    cout << ans << '\n';
    }
    return 0;
}
