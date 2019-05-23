#include <iostream>
#define maxn 200005
using namespace std;
int arr[maxn];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, sum = 0, odd = 0, even = 0;
	cin >> n;
	for ( int i=0; i<n; ++i ) {
		cin >> arr[i];
		sum += arr[i];
		if ( i&1 )	odd += arr[i];
		else	even += arr[i];
	}
	int odd2 = 0, even2 = 0, ans = 0;
	for ( int i=0; i<n; ++i ) {
		if ( ((sum-arr[i])&1) == 0 ) {
			if ( i&1 ) {
				if ( even2+odd-odd2-arr[i] == odd2+even-even2 )
					ans++;
			} else {
				if ( even2+odd-odd2 == odd2+even-even2-arr[i] )
					ans++;
			}
		}
		if ( i&1 )	odd2 += arr[i];
		else	even2 += arr[i];
	}
	cout << ans << '\n';
	return 0;
}

