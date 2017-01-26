#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
pii P[100010];
bool cmp ( pii a, pii b ) {
	return a.first < b.first;
}
main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, A, B, ans=1e9;
    cin >> N >> A >> B;
    for ( int i=0; i<N; i++ )
        cin >> P[i].first >> P[i].second;
    sort(P,P+N);
    if ( A == B )    cout << 0 << '\n';
    else {
        for ( int i=0; i<N; i++ )
            if ( P[i].first*A%B == 0 ) {
                int x = P[i].first*A/B;
                pii y = *lower_bound(P,P+N,pii{x,0},cmp);
                if ( y.first == x )
                    ans = min(ans,P[i].second+y.second);
            }
        if ( ans == 1e9 )    cout << -1 << '\n';
        else    cout << ans << '\n';
    }
    return 0;
}
