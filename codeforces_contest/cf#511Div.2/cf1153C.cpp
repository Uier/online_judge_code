#include <bits/stdc++.h>
#define maxn 300005
using namespace std;
int arr[maxn];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, len;
	string s;
	cin >> n >> s;
	len = s.size();
	int l = 0, r = 0, ans = 1;
	if ( len&1 )	return cout << ":(\n", 0;
	for ( int i=0; i<len; ++i ) {
		if ( s[i] == '(' )	l++;
		else if ( s[i] == ')' )	r++;
		arr[i] = l-r;
	}
	if ( l > len/2 || r > len/2 )	return cout << ":(\n", 0;
	int d = 0;
	for ( int i=0; i<len; ++i ) {
		if ( s[i] != '?' ) {
			if ( arr[i]+d <= 0 && i < len-1 ) {
				ans = 0;
				break;
			} 
			continue;
		}
//		cout << "x,arr[i],d: " << x << ' ' << arr[i] << ' ' << d << '\n';
//		cout << "i,len: " << i << ' ' << len << '\n';
		if ( len/2-l > 0 ) {
			s[i] = '(';
			l++;
			d++;
		} else {
			s[i] = ')';
			r++;
			d--;
		}
		if ( arr[i]+d <= 0 && i < len-1 ) {
			ans = 0;
			break;
		}
	}
	if ( ans ) {
		cout << s << '\n';
	} else {
		cout << ":(\n";
	}
	return 0;
}

