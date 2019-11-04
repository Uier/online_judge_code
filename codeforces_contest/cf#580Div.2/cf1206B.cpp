#include <iostream>
#define maxn 100005
using namespace std;
int arr[maxn];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, zero = 0, n1 = 0, p1 = 0;
	long long ans = 0;
	cin >> n;
	for ( int i=0; i<n; ++i ) {
		cin >> arr[i];
		if ( arr[i] <= -1 ) {
			ans += (-1-arr[i]);
			n1++;
		}
		else if ( arr[i] >= 1 ) {
			ans += (arr[i]-1);
			p1++;
		}
		else	zero++;
	}
	if ( (n1&1) && zero == 0 ) {
		cout << ans+2 << '\n';
	} else	cout << ans+zero << '\n';
	return 0;
}