#include <iostream>
using namespace std;
int st[105];
bool V[105];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string x, y;
	cin >> x >> y;
	int n = x.size();
	for ( int i=0; i<n; ++i ) {
		if ( x[i] == '0' && y[i] == '0' )	st[i] = 0;
		else if ( x[i] == '0' && y[i] == 'X' )	st[i] = 1;
		else if ( x[i] == 'X' && y[i] == '0' )	st[i] = 2;
		else	st[i] = 3;
	}
	int ans = 0, tmp = 0, row = 0;
	for ( int i=0; i<n; ++i ) {
		int l, r;
		bool la = false, ra = false;
		while ( i<n && st[i] != 0 )	i++;
		if ( i>0 && st[i-1] < 3 ) { // augment
			l = i-1;
			la = 1;
		} else l = i;
		while ( i<n && st[i] == 0 ) i++;
		i--;
		if ( i<n-1 && st[i+1] < 3 ) { // augment
			r = i+1;
			ra = 1;
			i++;
		} else r = i;
		int rl = l+(int)la, rr = r-(int)ra;
		if ( rl == rr ) {
			if ( la || ra )	ans++;
		} else {
			int k = (rr-rl)+1;
			ans += k/3*2;
			if ( k%3 == 1 && (la || ra) )	ans++;
			if ( k%3 == 2 ) {
				if ( la && ra )	ans += 2;
				else	ans++;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}

