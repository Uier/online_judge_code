#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm> 
using namespace std;
typedef pair<vector<int>,int> pvi;
int n, ed, cas;
map<vector<int>,bool> M;
vector<int> u, v;
queue<pvi> Q;
inline int bfs() {
	Q.push(pvi{u,0});
	M[u] = true;
	while ( !Q.empty() ) {
		pvi t = Q.front();	Q.pop();
		vector<int> tmp = t.first;
		int dep = t.second;
		vector<int> s = tmp;
		for ( int i=0; i<n; ++i ) {
			s[i] = 0;
			if ( !M[s] ) {
				M[s] = true;
				for ( int j : s )
					if ( j == ed )
						return dep+1;
				Q.push(pvi{s,dep+1});
			}
			s[i] = v[i];
			if ( !M[s] ) {
				M[s] = true;
				for ( int j : s )
					if ( j == ed )
						return dep+1;
				Q.push(pvi{s,dep+1});
			}
			s[i] = tmp[i]; // recover
		}
		for ( int i=0; i<n; ++i )
			for ( int j=0; j<n; ++j )
				if ( i != j ) {
					// pour i's water into j
					int remain = v[j]-s[j];
					if ( remain >= s[i] ) { // pour all
						s[j] += s[i];
						s[i] = 0;
					} else {
						s[j] = v[j];
						s[i] -= remain;
					}
					if ( !M[s] ) {
						M[s] = true;
						for ( int k : s )
							if ( k == ed )
								return dep+1;
						Q.push(pvi{s,dep+1});
					}
					s[i] = tmp[i], s[j] = tmp[j]; // recover
				}
	}
	return -1;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int mx = 0, gcd;
	cin >> n;
	for ( int i=0, x; i<n; ++i ) {
		cin >> x;
		mx = max(mx,x);
		if ( i )	gcd = __gcd(gcd,x);
		else	gcd = x;
		u.emplace_back(0);
		v.emplace_back(x);
	}
	cin >> ed;
	if ( ed > mx || ed%gcd )
		cout << -1 << '\n';
	else
		cout << bfs() << '\n';
	return 0;
}
