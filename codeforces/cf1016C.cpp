#include <iostream>
#define maxn 300005
using namespace std;
long long a[maxn], b[maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n;
	for ( int i=0; i<n; ++i )	cin >> a[i];
	for ( int i=0; i<n; ++i )	cin >> b[i];
	if ( n == 1 ) {
		cout << b[0] << '\n';
	} else if ( n&1 ) {
		m = n-3;
		long long x = a[m]*0+a[m+1]*1+a[m+2]*2+b[m+2]*3+b[m+1]*4+b[m]*5;
		long long y = a[m]*0+b[m]*1+b[m+1]*2+a[m+1]*3+a[m+2]*4+b[m+2]*5;
		long long z = a[m]*0+b[m]*1+b[m+1]*2+b[m+2]*3+a[m+2]*4+a[m+1]*5;
		long long ans = max(x,max(y,z));
		long long ori = a[m]+a[m+1]+a[m+2]+b[m+2]+b[m+1]+b[m];
		for ( int i=m-2; i>=0; i-=2 ) {
			long long nex = a[i]*0+a[i+1]*1+(x+ori*2)+b[i+1]*((n-i)*2-2)+b[i]*((n-i)*2-1);
			long long ney = a[i]*0+b[i]*1+b[i+1]*2+a[i+1]*3+(ans+ori*4);
			long long nez = a[i]*0+b[i]*1+b[i+1]*2+(z+(ori-a[i+2])*2)+a[i+2]*((n-i)*2-2)+a[i+1]*((n-i)*2-1);
			ans = max(nex,max(ney,nez));
			x = nex;
			y = ney;
			z = nez;
			ori += a[i]+a[i+1]+b[i]+b[i+1];
		}
		cout << ans << '\n';
	} else {
		m = n-2;
		long long x = a[m]*0+a[m+1]*1+b[m+1]*2+b[m]*3;
		long long y = a[m]*0+b[m]*1+b[m+1]*2+a[m+1]*3;
		long long z = a[m]*0+b[m]*1+b[m+1]*2+a[m+1]*3;
		long long ans = max(x,max(y,z));
		long long ori = a[m]+a[m+1]+b[m+1]+b[m];
		for ( int i=m-2; i>=0; i-=2 ) {
			long long nex = a[i]*0+a[i+1]*1+(x+ori*2)+b[i+1]*((n-i)*2-2)+b[i]*((n-i)*2-1);
			long long ney = a[i]*0+b[i]*1+b[i+1]*2+a[i+1]*3+(ans+ori*4);
			long long nez = a[i]*0+b[i]*1+b[i+1]*2+(z+(ori-a[i+2])*2)+a[i+2]*((n-i)*2-2)+a[i+1]*((n-i)*2-1);
			ans = max(nex,max(ney,nez));
			x = nex;
			y = ney;
			z = nez;
			ori += a[i]+a[i+1]+b[i]+b[i+1];
		}
		cout << ans << '\n';
	}
	return 0;
}
