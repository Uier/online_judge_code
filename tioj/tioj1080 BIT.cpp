#include <iostream>
#include <algorithm>
#include <string.h>
#define maxn 100005
using namespace std;
int n, t = 1, bit[maxn], a[maxn], s[maxn];
long long ans;
void add(int i) {
	for ( ; i<=n; i+=(i&-i) )	bit[i]++;
}
int sum(int i) {
	int x = 0;
	for ( ; i>0; i-=(i&-i) )	x += bit[i];
	return x;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	while ( cin >> n && n ) {
		ans = 0;
		memset(bit,0,sizeof(bit));
		for ( int i=1; i<=n; s[i]=a[i], ++i )	cin >> a[i];
		sort(s+1,s+1+n);
		for ( int i=1; i<=n; ++i ) {
			int x = lower_bound(s+1,s+1+n,a[i])-s;
			add(x);
			ans += i-sum(x);
		}
		cout << "Case #" << t++ << ": " << ans << '\n';
	}
	return 0;
}

