#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#define maxn 100005
using namespace std;
vector<int> a, b;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, x;
	cin >> n >> m;
	for ( int i=0; i<n; ++i ) {
		cin >> x;
		a.emplace_back(x);
	}
	for ( int i=0; i<m; ++i ) {
		cin >> x;
		b.emplace_back(x);
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	long long ans = 1e15;
	for ( int i=0; i<n; ++i ) {
		auto tmp = lower_bound(b.begin(),b.end(),a[i]);
		if ( tmp != b.end() )
			ans = min(ans,(long long)abs(*tmp-a[i]));
	}
	for ( int i=0; i<m; ++i ) {
		auto tmp = lower_bound(a.begin(),a.end(),b[i]);
		if ( tmp != a.end() )
			ans = min(ans,(long long)abs(*tmp-b[i]));
	}
	cout << ans << '\n';
	return 0;
}

