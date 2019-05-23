#include <iostream>
#include <vector>
#include <algorithm>
#define maxn 100005
using namespace std;
int arr[maxn];
vector<int> d;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k >> arr[0];
	for ( int i=1; i<n; ++i ) {
		cin >> arr[i];
		d.emplace_back(arr[i]-arr[i-1]);
	}
	sort(d.begin(),d.end());
	long long ans = k;
	for ( int i=0; i<n-k; ++i )	ans += d[i];
	cout << ans << '\n';
	return 0;
}

