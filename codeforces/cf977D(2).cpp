#include <iostream>
#include <vector>
#define maxn 105
using namespace std;
long long n, a[maxn];
vector<int> G[maxn], sol;
bool dfs(int x, int dep) {
	if ( dep == n )	return true;
	for ( int i : G[x] ) {
		sol.emplace_back(i);
		if ( dfs(i,dep+1) )	return true;
		sol.pop_back();
	}
	return false;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for ( int i=0; i<n; ++i )
		cin >> a[i];
	for ( int i=0; i<n; ++i )
		for ( int j=i+1; j<n; ++j ) {
			if ( a[i]*2 == a[j] || (a[i]%3 == 0 && a[i]/3 == a[j]) )
				G[i].emplace_back(j);
			if ( a[j]*2 == a[i] || (a[j]%3 == 0 && a[j]/3 == a[i]) )
				G[j].emplace_back(i);
		}
	for ( int i=0; i<n; ++i ) {
		sol.emplace_back(i);
		if ( dfs(i,1) )	break;
		sol.pop_back();
	}
	for ( int i : sol )	cout << a[i] << ' ';
	cout << '\n';
	return 0;
}

