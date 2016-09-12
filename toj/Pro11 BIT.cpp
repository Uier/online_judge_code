#include <stdio.h>
using namespace std;
int a[2000003], n, x;
long long ans=0;
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
	scanf("%d", &n);
	for ( int i=1; i<=n; i++ ) {
		scanf("%d", &x);
		add(x);
		ans += i-sum(x);
	}
	printf("%lld\n", ans);
	return 0;
}

