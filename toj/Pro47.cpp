#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define int long long
vector<int> V;
main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n;
    while ( n-- ) {
        int x;
        cin >> x;
        V.push_back(x);
    }
    sort(V.begin(),V.begin()+V.size());
    cin >> q;
    while ( q-- ) {
        int x;
        cin >> x;
        auto i = lower_bound(V.begin(),V.end(),x);
        if ( *i == x )    cout << x << '\n';
        else if ( x < *V.begin() )    cout << "no " << *i << '\n';
        else if ( x > *(V.end()-1) )	cout << *(V.end()-1) << " no\n";
        else cout << *(i-1) << ' ' << *i << '\n';
    }
    return 0;
}
