#include <iostream>
#include <set> 
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
set<int> S;
map<int,int> M;
vector<int> V;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k, x;
	cin >> n >> k;
	for ( int i=1; i<=n; ++i ) {
		cin >> x;
		if ( M[x] == 0 )	M[x] = i;
		S.insert(x);
	}
	if ( S.size() < k )	cout << "NO\n";
	else {
		int cnt = 0;
		cout <<"YES\n";
		for ( auto i=S.begin(); i!=S.end(); ++i ) {
			if ( cnt == k )	break;
			cout << M[*i] <<' ';
			cnt++;
		}
			
	}
	cout <<'\n';
	return 0;
}

