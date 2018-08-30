#include <iostream>
#include <map>
#define maxn 200005
using namespace std;
int a[maxn], dp[maxn];
map<int,int> M;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, pos = -1;
	cin >> n >> m;
	for ( int i=0; i<n; ++i ) {
		cin >> a[i];
		if ( a[i] == m )	pos = i;
	}
	int upper = 0, lower = 0;
	for ( int i=pos-1; i>=0; --i ) {
		if ( a[i] < m )	lower++;
		else upper++;
		dp[i] = upper-lower;
	}
	upper = 0;	lower = 0;
	for ( int i=pos+1; i<n; ++i ) {
		if ( a[i] < m )	lower++;
		else	upper++;
		M[upper-lower]++;
	}
	M[0]++;
	long long ans = 0;
	for ( int i=0; i<=pos; ++i ) {
		int x = -dp[i];
		ans += M[x];
		x++;
		ans += M[x];
	}
	cout << ans << '\n';
	return 0;
}

