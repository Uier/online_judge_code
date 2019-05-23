#include <iostream>
#define int long long
using namespace std;
int mod = 1e9+7;
int f(int x) {
    int s = 1;
    for ( int i=2; i<=x; ++i )    s = (s*i)%mod;
    return s;
}
int _pow(int a, int b) {
    int ans = 1;
    while ( b ) {
        if ( b&1 )    ans *= a;
        a *= a;
        a %= mod;
        ans %= mod;
        b >>= 1;
    }
    return ans;
}
main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    if ( m == 1 )	return cout << n << '\n', 0;
    int x = f(n+m-1)*_pow(f(n-1)*f(m)%mod,mod-2)%mod;
    int y = f(n+m-1)*_pow(f(n+1)*f(m-2)%mod,mod-2)%mod;
    cout << (x-y+mod)%mod << '\n';
    return 0;
}
