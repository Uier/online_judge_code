#include <iostream>
using namespace std;
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	long long la, ra, lb, rb, k, ans=0;
	cin >> la >> ra >> lb >> rb >> k;
	if ( lb >= la && lb <= ra && rb >= la && rb <= ra ) {
		ans = rb-lb+1;
		if ( lb <= k && k <= rb )
			ans--;
	}
	else if ( lb >= la && lb <= ra ) {
		ans = ra-lb+1;
		if ( lb <= k && k <= ra )
			ans--;
	}
	else if ( rb >= la && rb <= ra ) {
		ans = rb-la+1;
		if ( la <= k && k <= rb )
			ans--;
	}
	else if ( lb <= la && rb >= ra ) {
		ans = ra-la+1;
		if ( la <= k && k <= ra )
			ans--;
	}
	cout << ans << '\n';
	return 0;
}

