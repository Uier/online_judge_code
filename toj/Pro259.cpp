#include <iostream>
#include <vector>
using namespace std;
int n, ans, a[10005], d[10005], p[10005];
inline int lis(int dp[]) {
	vector<int> r, s;	r.clear();	s.clear();
	r.push_back(dp[0]);	s.push_back(dp[n-1]);
	ans = d[0] = p[n-1] = 1;
	for ( int i=1, j=n-2; i<n; i++, j-- ) {
		if ( dp[i] > r.back() )	
			r.push_back(dp[i]);
		else
			*lower_bound(r.begin(),r.end(),dp[i]) = dp[i];
		if ( dp[j] > s.back() )	
			s.push_back(dp[j]);
		else
			*lower_bound(s.begin(),s.end(),dp[j]) = dp[j];
		d[i] = r.size();	p[j] = s.size();
	}
	for ( int i=0; i<n; i++ )
		ans = max(ans,min(d[i],p[i]));
	return ans*2-1;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	while ( cin >> n ) {
		for ( int i=0; i<n; i++ )
			cin >> a[i];
		cout << lis(a) << '\n';
	}
	return 0;
}

