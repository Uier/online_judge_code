#include <bits/stdc++.h>
using namespace std;
int digit(int x) {
    int ans = 0;
    while ( x > 0 ) {
        ans++;
        x /= 10;
    }
    return ans;
}
int mypow(int x, int y) {
    int ans = 1;
    for ( int i=0; i<y; ++i ) {
        ans *= x;
    }
    return ans;
}
int main() {
    int n, m;
    while ( cin >> n >> m ) {
        bool first = true;
        for ( int i=n; i<=m; ++i ) {
            int cnt = digit(i);
            int sum = 0, j = i;
            while ( j > 0 ) {
                sum += mypow(j%10,cnt);
                j /= 10;
            }
            if ( sum == i ) {
                if ( first ) {
                    first = false;
                    cout << i;
                } else {
                    cout << ' ' << i;
                }
            }
        }
        if ( first ) {
            cout << "none" << endl;
        } else {
            cout << endl;
        }
    }
    return 0;
}
