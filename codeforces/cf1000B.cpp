#include <iostream>
#define maxn 100005
using namespace std;
int a[maxn], s[maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	a[n+1] = m;
	bool neg = false;
	for ( int i=1; i<=n; ++i ) {
		cin >> a[i];
		s[i-1] = a[i]-a[i-1];
		if ( neg )	s[i-1] *= -1;
		neg ^= 1;
	} s[n] = m-a[n];
	if ( neg )	s[n] *= -1;
	int sum = s[n], min = s[n], id = n, pos = 0;
	for ( int i=n-1; i>=0; --i ) {
		sum += s[i];
		if ( sum <= min ) {
			min = sum;
			id = i;
		}
	}
	if ( min >= 0 )	{
		for ( int i=0; i<=n; ++i )
			if ( s[i] > 0 )	pos += s[i];
		cout << pos << '\n';
	} else {
		int ans = m-1;
		for ( int i=id; i<=n; ++i )
			if ( s[i] > 0 )	ans -= s[i];
		cout << ans << '\n';
	}
	return 0;
}

