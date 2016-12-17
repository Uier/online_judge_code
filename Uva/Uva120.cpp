#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
vector<int> v;
//	nonononononono
void solve(int n) {
	if ( v[n-1] == n )
		if ( n == 1 )	return;
		else	solve(n-1);
	else {
		if ( v[0] != n ) {
			int z = 0;
			for ( int i=0; i<n-1; i++ )
				if ( v[i] == n )
					z = i+1;
			cout << z << ' ';
			for ( int i=0; i<z/2; i++ )
				swap(v[i],v[z-1-i]);
		}
		cout << v.size()-n+1 << ' ';
		for ( int i=0; i<n/2; i++ )
			swap(v[i],v[n-1-i]);
		solve(n-1);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	while ( getline(cin,s) ) {
		v.clear();
		istringstream ss(s);
		int x;
		while ( ss >> x )
			v.push_back(x);
		for ( int i=0; i<v.size(); i++ )
			cout << v[i] << ((i==v.size()-1) ? '\n' : ' ');
		solve(v.size());
		cout << 0 << '\n';
	}
	return 0;
}

