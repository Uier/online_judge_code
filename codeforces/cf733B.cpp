#include <iostream>
#include <math.h>
using namespace std;
int l[100010], r[100010];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	long long suml=0, sumr=0, ans=0, x=0, y=0;
	for ( int i=0; i<n; i++ ) {
		cin >> l[i] >> r[i];
		suml += l[i];
		sumr += r[i];
	}
	x = abs(suml-sumr);
	if ( sumr > suml )
		for ( int i=0; i<n; i++ ) {
			if ( l[i]-r[i] > y ) {
				ans = i+1;
				y = l[i]-r[i];
			}
			else if ( r[i]-l[i]-x > y ) {
				ans = i+1;
				y = r[i]-l[i]-x;
			}
		}
	else
		for ( int i=0; i<n; i++ ) {
			if ( r[i]-l[i] > y ) {
				ans = i+1;
				y = r[i]-l[i];
			}
			else if ( l[i]-r[i]-x > y ) {
				ans = i+1;
				y = l[i]-r[i]-x;
			}
		}
	cout << ans << '\n';
	return 0;
}

