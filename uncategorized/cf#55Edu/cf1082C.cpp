#include <iostream>
#include <algorithm>
#include <vector>
#define maxn 100005
#define int long long
using namespace std;
typedef pair<int,int> pii;
pii arr[maxn];
int sum[maxn];
vector<int> G[maxn];
main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for ( int i=0; i<n; ++i )	cin >> arr[i].first >> arr[i].second;
	sort(arr,arr+n);
	reverse(arr,arr+n);
	int pre = 0, pre_sum = 0, idx = 0;
	for ( int i=0; i<n; ++i ) {
		if ( arr[i].first == pre )	pre_sum += arr[i].second;
		else {
			idx = 1;
			pre = arr[i].first;
			pre_sum = arr[i].second;
		}
		if ( pre_sum > 0 )	sum[idx++] += pre_sum;
	}
	int mx = 0;
	for ( int i=1; i<=n; ++i )
		mx = max(mx,sum[i]);
	cout << mx << '\n';
	return 0;
}

