#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t, cs = 1;
	string s;
	cin >> t;
	while ( t-- && cin >> s ) {
		string x = "", y = "";
		int carry = 0;
		for ( int i=0; i<s.size(); ++i ) {
			int dig = carry*10+(s[i]-'0');
			carry = (dig&1);
			if ( x.size() == 0 && (dig>>1) == 0 )	continue;
			x.push_back('0'+(dig>>1));
			y.push_back('0'+(dig>>1));
		}
		if ( carry ) {
			int n = 0;
			for ( int i=0; i<y.size(); ++i ) {
				n = n*10+(y[i]-'0');
			}	
			n++;
			y = "";
			while ( n ) {
				y.push_back(('0'+n%10));
				n /= 10;
			}
			reverse(y.begin(),y.end());
		}
		reverse(x.begin(),x.end());
		reverse(y.begin(),y.end());
		for ( int i=0; i<x.size(); ++i ) {
			if ( x[i] == '4' ) {
				if ( y[i] == '3' ) {
					x[i]++;
					y[i]--;
				} else {
					x[i]--;
					y[i]++;
				}
			} else if ( y[i] == '4' ) {
				if ( x[i] == '3' ) {
					x[i]--;
					y[i]++;
				} else {
					x[i]++;
					y[i]--;
				}
			}
		}
		reverse(x.begin(),x.end());
		reverse(y.begin(),y.end());
		cout << "Case #" << cs++ << ": " << x << ' ' << y << '\n';
	}
	return 0;
}

