#include <bits/stdc++.h>
using namespace std;
map<string,int> M;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	double n, sum = 0;
	cin >> n;
	string s;
	getline(cin,s);
	getline(cin,s);
	while ( n-- ) {
		M.clear();
		if ( sum ) {
			cout << '\n';
			sum = 0;
		}
		while ( getline(cin,s) && s != "" )
			M[s]++, sum++;
		for ( map<string,int>::iterator i=M.begin(); i!=M.end(); ++i )
			cout << i->first << ' ' << fixed << setprecision(4) << (double)(i->second)/sum*100 << '\n';
	}
	return 0;
}

