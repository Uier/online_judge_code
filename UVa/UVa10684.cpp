#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, x;
	while ( cin >> N && N ) {
		int sum = 0, ans = -1e9;
		for ( int i=0; i<N; ++i ) {
			cin >> x;
			if ( sum < 0 )	sum = 0;
			sum += x;
			ans = max(ans,sum);
		}
		if ( ans > 0 )	cout << "The maximum winning streak is " << ans << ".\n";
		else	cout << "Losing streak.\n";
	}
	return 0;
}

