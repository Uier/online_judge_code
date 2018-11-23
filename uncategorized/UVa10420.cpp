#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
typedef pair<string,int> psi;
map<string,int> M;
map<int,string> rM;
set<string> S[2005];
psi arr[2005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, cnt = 1;
	string s, name;
	cin >> t;
	while ( t-- && cin >> s ) {
		int x = M[s];
		if ( !x )	x = M[s] = cnt++;
		rM[M[s]] = s;
		getline(cin,name);
		S[M[s]].insert(name);
	}
	for ( int i=1; i<cnt; ++i ) {
		arr[i] = psi{rM[i],S[i].size()};
	}
	sort(arr+1,arr+cnt);
	for ( int i=1; i<cnt; ++i ) {
		cout << arr[i].first << ' ' << arr[i].second << '\n';
	}
	return 0;
}

