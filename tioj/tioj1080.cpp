#include <stdio.h>
//	fail  ­n¥Îmerge 
using namespace std;
int n, m, x, a[100005];
long long ans;
int sum(int i) {
	if ( i > 0 )
		return a[i]+sum(i-(i&-i));
	return 0;
}
void add(int i) {
	if ( i > n )
		return;
	a[i]++;
	add(i+(i&-i));
}
int main() {
	while ( scanf("%d", &n) != EOF && n != 0 ) {
		m++;
		for ( int i=1; i<=n; i++ )	a[i] = 0;
		ans = 0;
		for ( int i=1; i<=n; i++ ) {
			scanf("%d", &x);
			add(x);
			ans += i-sum(x);
		}
		printf("Case #%d: %lld\n", m, ans);
	}
	return 0;
}

