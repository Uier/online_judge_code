#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
using namespace std;
int x, y, z, a[50];	// y = v.size();
vector<int> v;
void solve(int n) {
	if ( v[n] == a[n] ) {
		if ( n == 0 )	return;
		else	solve(n-1);
	}
	else {
		if ( v[0] != a[n] ) {
			for ( int i=0; i<n; i++ )
				if ( v[i] == a[n] )
					z = i;
			cout << y-z << ' ';
			for ( int i=0; i<(z+1)/2; i++ )
				swap(v[i],v[z-i]);
			if ( v[n] == a[n] ) {
				if ( n == 0 )	return;
				else	solve(n-1);
			}
		}
		cout << y-n << ' ';
		for ( int i=0; i<(n+1)/2; i++ )
			swap(v[i],v[n-i]);
		solve(n-1);
	}
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	string s;
	while ( getline(cin,s) ) {
		v.clear();
		istringstream ss(s);
		y = 0;
		while ( ss >> x ) {
			v.push_back(x);
			a[y++] = x;
		}
		sort(a,a+v.size());
		cout << s << '\n';
		solve(v.size()-1);
		cout << 0 << '\n';
	}
	return 0;
}
