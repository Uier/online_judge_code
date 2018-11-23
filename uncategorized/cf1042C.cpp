#include <iostream>
#include <math.h>
#define maxn 200005
using namespace std;
int arr[maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, mn = 2e9, mxneg = -2e9, cnt = 0, cnt2 = 0, idx = -1, idx2 = -1;
	cin >> n;
	for ( int i=1; i<=n; ++i ) {
		cin >> arr[i];
		if ( arr[i] < 0 ) {
			if ( arr[i] > mxneg ) {
				mxneg = arr[i];
				idx = i;
			}
			cnt++;
		} else {
			if ( arr[i] <= mn ) {
				mn = min(mn,arr[i]);
				idx2 = i;
			}
			if ( arr[i] == 0 )	cnt2++;
		}
	}
	if ( cnt&1 ) {
		if ( mn == 0 ) {
			int ididx = -1, ans = 0;
			for ( int i=1; i<=n; ++i ) {
				if ( i == idx )	continue;
				if ( arr[i] == 0 ) {
					cout << 1 << ' ' << i << ' ' << idx << '\n';
					ans++;
				} else {
					if ( ididx == -1 )	ididx = i;
					else {
						cout << 1 << ' ' << i << ' ' << ididx << '\n';
						ans++;
					}
				}
			}
			if ( ans == n-2 )
				cout << 2 << ' ' << idx << '\n';
		} else {
			cout << 2 << ' ' << idx << '\n';
			int ididx = -1;
			for ( int i=1; i<=n; ++i ) {
				if ( i == idx )	continue;
				if ( ididx == -1 )	ididx = i;
				else
					cout << 1 << ' ' << i << ' ' << ididx << '\n';
			}
		}
	} else {
		if ( mn == 0 ) {
			if ( cnt2 > 1 ) {
				int ididx = -1, ans = 0;
				for ( int i=1; i<=n; ++i ) {
					if ( i == idx2 )	continue;
					if ( arr[i] == 0 ) {
						cout << 1 << ' ' << i << ' ' << idx2 << '\n';
						ans++;
					} else {
						if ( ididx == -1 )	ididx = i;
						else {
							cout << 1 << ' ' << i << ' ' << ididx << '\n';
							ans++;
						}
					}
				}
				if ( ans == n-2 )
					cout << 2 << ' ' << idx2 << '\n';
			} else {
				cout << 2 << ' ' << idx2 << '\n';
				int ididx = -1;
				for ( int i=1; i<=n; ++i ) {
					if ( i == idx2 )	continue;
					if ( ididx == -1 )	ididx = i;
					else
						cout << 1 << ' ' << i << ' ' << ididx << '\n';
				}
			}
		} else {
			for ( int i=1; i<n; ++i ) {
				cout << 1 << ' ' << i << ' ' << i+1 << '\n';
			}
		}
	}
	return 0;
}

