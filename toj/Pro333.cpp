#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, a, b;
    long long ans=0;
    cin >> n >> a;
    if ( n == 1 )
        cout << a << '\n';
    else {
        m = n-2;
        while ( m-- ) {
            cin >> b;
            if ( a-b > 0 )
                ans += a-b;
            a = b;
        }
        cin >> b;
        ans += max(a,b);
        cout << ans << '\n';
    }
    return 0;
}
