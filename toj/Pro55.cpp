#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q, x;
    cin >> n;
    for ( int i=0; i<n; i++ )
        cin >> a[i];
    sort(a,a+n);
    cin >> q;
    while ( q-- ) {
        cin >> x;
        cout << upper_bound(a,a+n,x)-lower_bound(a,a+n,x) << '\n';
    }
    return 0;
}
