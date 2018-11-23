#include <iostream>
#include <vector>
#include <set>
#define maxn 100005
#define int long long
using namespace std;
int n, npr[maxn], arr[maxn];
set<int> G[maxn];
const long long mod = 1000000007;
long long dfs(int x, int l) {
	long long s = 1;
	auto i = G[x].lower_bound(l);
	for ( ;i!=G[x].end(); ++i ) {
		if ( x == 2 )	s += dfs(x+1,*i)*(*i-1);
		else	s += dfs(x+1,*i);
		s %= mod;
	}
	return s%mod;
}
main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	for ( int i=2; i<maxn; ++i )
		if ( !npr[i] )
			for ( int j=i*i; j<maxn; j+=i )
				npr[j] = i;
	cin >> n;
	for ( int i=1, x; i<=n; ++i ) {
		cin >> arr[i];
		x = arr[i];
		G[x].insert(i);
		while ( npr[x] ) {
			G[npr[x]].insert(i); 
			x /= npr[x];
		}
	}
	cout << dfs(2,2)+n-1 << '\n';
	return 0;
}

