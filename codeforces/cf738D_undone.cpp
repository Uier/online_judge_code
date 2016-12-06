#include <iostream>
#include <vector>
using namespace std;
typedef pair<int,int> P;
vector<P> v;
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int n, a, b, k;	
	string s;
	// n = length of grid, a = N(ship), b = length of ship, k = shot
	cin >> n >> a >> b >> k >> s;
	for ( int i=0; i<s.size(); i++ ) {
		bool x=0;
		int y=0
		if ( s[i] == 1 && x ) {
			v.push_back({i-y-1,i+1});
			y = i;
		}
		else if ( s[i] == 1 ) {
			a = true;
			v.push_back({i,i+1});
			y = i;
		}
		else if ( i == s.size()-1 && x )
			v.push_back({i-y,i+1});
	}
	if ( a > v.size() ) {
		int m = a-v.size();
		for ( int i : v ) {
			if ( i >
		}
	}
	else if ( a == v.size() ) {
		
	}
	else {
		
	}
	return 0;
}

