#include <iostream>
#include <stack>
using namespace std;
typedef pair<int,int> pii;
stack<pii> S;
int dp[10000005];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    while ( cin >> n >> x ) {
        while ( !S.empty() )    S.pop();
        S.push({x,0});    cout << 0;    dp[0] = 0;
        for ( int i=1; i<n; ++i ) {
            cin >> x;
            if ( x <= S.top().first ) {
                S.push(pii{x,i});
                dp[i] = 0;
                cout << ' ' << 0;
            } else {
                pii tmp;
                while ( !S.empty() && x > S.top().first ) {
                    tmp = S.top();
                    S.pop();
                }
                S.push(pii{x,i});
                dp[i] = dp[tmp.second] + (i-tmp.second);
                cout << ' ' << dp[i];
            }
        }
        cout << '\n';
    }
    return 0;
}
// array version
//#include <iostream>
//using namespace std;
//typedef pair<int,int> pii;
//pii S[1000005];
//int dp[1000005];
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	int n, x;
//	while ( cin >> n >> x ) {
//		int pt = 0;
//		S[pt++] = pii{x,0};	cout << 0;	dp[0] = 0;
//		for ( int i=1; i<n; ++i ) {
//			cin >> x;
//			if ( x <= S[pt-1].first ) {
//				S[pt++] = pii{x,i};
//				dp[i] = 0;
//				cout << ' ' << 0;
//			} else {
//				pii tmp;
//				while ( pt && x > S[pt-1].first ) {
//					tmp = S[pt-1];
//					pt--;
//				}
//				S[pt++] = pii{x,i};
//				dp[i] = dp[tmp.second] + (i-tmp.second);
//				cout << ' ' << dp[i];
//			}
//		}
//		cout << '\n';
//	}
//	return 0;
//}

