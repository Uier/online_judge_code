#include <iostream>
using namespace std;
int main() {
	int n, m, sum = 0;
	int arr[25] = {0};
	cin >> n >> m;
	for ( int i=0; i<n; ++i ) {
		int mx = 0;
		for ( int j=0, x; j<m; ++j ) {
			cin >> x;
			if ( x > mx ) {
				mx = x;
			}
		}
		arr[i] = mx;
		sum += mx;
	}
	cout << sum << '\n';
	int ans[25] = {0}, ans_pt = 0;
	for ( int i=0; i<n; ++i ) {
		if ( sum%arr[i] == 0 ) {
			ans[ans_pt] = arr[i];
			ans_pt++;
		}
	}
	if ( ans_pt == 0 ) {
		cout << "-1\n";
	} else {
		cout << ans[0];
		for ( int i=1; i<ans_pt; ++i ) {
			cout << ' ' << ans[i];
		}
		cout << '\n';
	}
	return 0;
}

