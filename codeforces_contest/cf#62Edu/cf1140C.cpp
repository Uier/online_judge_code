#include <iostream>
#include <algorithm>
#include <queue>
#define maxn 300005
#define int long long
using namespace std;
typedef pair<int,int> pii;
pii arr[maxn];
priority_queue<int,vector<int>,greater<int>> PQ;
bool cmp(pii x, pii y) {
	if ( x.second == y.second )	return x.first > y.first;
	return x.second > y.second;
}
main() {
	ios::sync_with_stdio(false);
	//   sync_with_YinHsuan(true);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	for ( int i=0; i<n; ++i )	cin >> arr[i].first >> arr[i].second;
	sort(arr,arr+n,cmp);
	int ans = 0, mn = 1e6, sum = 0;
	for ( int i=0; i<k; ++i ) {
		sum += arr[i].first;
		mn = min(mn,arr[i].second);
		ans = max(ans,sum*mn);
		PQ.push(arr[i].first);
	}
	for ( int i=k; i<n; ++i ) {
		mn = min(mn,arr[i].second);
		if ( !PQ.empty() && arr[i].first > PQ.top() ) {
			sum -= PQ.top();
			PQ.pop();
			sum += arr[i].first;
			PQ.push(arr[i].first);
		}
		ans = max(ans,sum*mn);
	}
	cout << ans << '\n';
	return 0;
}

