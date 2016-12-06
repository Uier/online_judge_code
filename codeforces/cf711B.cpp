#include <iostream>
#include <set>
#include <math.h>
using namespace std;
typedef long long ll;
ll g[505][505], r[505], c[505], m[2], em[2];
bool emm[2];
set<ll> st;
int main()
{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int n;
	cin >> n;
	st.clear();
	for ( int i=0; i<n; i++ )
		for ( int j=0; j<n; j++ ) {
			cin >> g[i][j];
			r[i] += g[i][j];
			c[j] += g[i][j];
			if ( g[i][j] == 0 ) {
				em[0] = i;
				em[1] = j;
			}
			if ( i == j ) {
				m[0] += g[i][j];
				if ( g[i][j] == 0 )
					emm[0] = true;
			}
			if ( i+j == n-1 ) {
				m[1] += g[i][j];
				if ( g[i][j] == 0 )
					emm[1] = true;
			}
		}
	for ( int i=0; i<n; i++ ) {
		if ( em[0] == i )
			st.insert(-r[i]);
		else
			st.insert(r[i]);
		if ( em[1] == i )
			st.insert(-c[i]);
		else
			st.insert(c[i]);
	}
	if ( emm[0] )
		st.insert(-m[0]);
	else
		st.insert(m[0]);
	if ( emm[1] )
		st.insert(-m[1]);
	else
		st.insert(m[1]);
	if ( n == 1 )
		cout << 1 << '\n';
	else if ( st.size() > 2 )
		cout << -1 << '\n';
	else {
		ll ans[2]={0,0};
		int x=0;
		for ( ll i : st )
			ans[x++] = i;
		if ( ans[0] < ans[1] )
			swap(ans[0],ans[1]);
		cout << ans[0]-ans[1] <<'\n';
	} 
	return 0;
}

