#include <iostream>
using namespace std;
typedef long long ll;
ll n, ql, qr, s = 1, ans;
void find(ll a, ll b, ll l, ll r, ll d) {
	if ( a > b || l > r )	return;
	if ( l == a && r == b ) {
		ans += d;
		return;
	} else {
		ll mid = (a+b)/2;
		if ( r < mid )	find(a,mid-1,l,r,d/2);
		else if ( mid < l )	find(mid+1,b,l,r,d/2);
		else {
			ans += d%2;
			find(a,mid-1,l,mid-1,d/2);
			find(mid+1,b,mid+1,r,d/2);
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> ql >> qr;
	long long p = n;
	while ( p >= 2 ) {
		p /= 2;
		s = s*2+1;
	}
	find(1,s,ql,qr,n);
	cout << ans << '\n';
	return 0;
}

