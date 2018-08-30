#include <iostream>
#include <vector>
using namespace std;
int N, K;
long long ans, mod = 1000000007;
vector<int> s;
void dfs(int l, int n, int sz) {
	if ( sz > K )	return;
	if ( n == 0 && sz == K ) {
		for ( int i : s ) {
			ans += i*i;
			ans %= mod;
		}
		return;
	}
	for ( int i=l; i<=N; ++i ) {
		if ( n-i < 0 )	break;
		s.emplace_back(i);
		dfs(i,n-i,sz+1);
		s.pop_back();
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	dfs(1,N,0);
	cout << ans << '\n';
	return 0;
}

