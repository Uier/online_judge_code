#include <iostream>
#include <algorithm>
using namespace std;
int a[100005], b[100005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T, N, Tcase = 1;
	cin >> T;
	while ( T-- && cin >> N ) {
		int len_a = N/2, len_b = N/2;
		for ( int i=0; i<N/2; ++i )
			cin >> a[i] >> b[i];
		if ( N&1 ) {
			cin >> a[N/2];
			len_a++;
		}
		sort(a,a+len_a);
		sort(b,b+len_b);
		int pre = 0, ans = 0;
		for ( int i=0; i<len_b; ++i ) {
			if ( a[i] < pre ) {
				ans = i*2;	break;
			}
			if ( b[i] < a[i] ) {
				ans = i*2+1;	break;
			}
			pre = b[i];
		}
		if ( N&1 && a[N/2] < pre && ans == 0 )	ans = N-1;
		if ( ans == 0 )	cout << "Case #" << Tcase++ << ": OK\n";
		else	cout << "Case #" << Tcase++ << ": " << ans-1 << '\n';
	}
	return 0;
}

