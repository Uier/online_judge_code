#include <iostream>
#include <vector>
using namespace std;
vector<int> a;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, x = 0;
	string s;
	cin >> n;
	cin >> s;
	a.emplace_back(0);
	for ( int i=0; i<n; ++i ) {
		if ( s[i] == 'x' )	x++;
		else	x = 0;
		if ( x == 0 )
			a.emplace_back(x);
		else
			a.back()++;
	}
	int cnt = 0;
	for ( int i : a )
		if ( i >= 3 )
			cnt += i-2;
	cout << cnt << '\n';
	return 0;
}

