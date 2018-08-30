#include <iostream>
#include <map>
#define maxn 1000005
using namespace std;
int n, a[maxn], pre[maxn], bit[maxn];
map<int,int> M;
inline void add(int i) {
	for ( ; i<n; i+=(i&-i) )	bit[i]++;
}
inline int sum(int i, int s=0) {
	for ( ; i>0; i-=(i&-i) )	s += bit[i];
	return s;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for ( int i=0; i<n; ++i ) {
		cin >> a[i];
		pre[i] = ++M[a[i]];
	}
	long long ans = 0;
	for ( int i=0, x; i<n; ++i ) {
		x = M[a[i]]-pre[i]+1;
		ans += i-sum(x);
		add(pre[i]);
	}
	cout << ans << '\n';
	return 0;
}
