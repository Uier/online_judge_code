#include <iostream>
#include <vector> 
#include <algorithm>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
vector<pii> v;
ll calc(pii a, pii b) {return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);}
inline bool cmpy(pii a, pii b) {return a.y < b.y;}
ll divide(int l, int r) {
	if ( r-l == 1 )
		return calc(v[l],v[r]);
	if ( r-l <= 3 ) {
		ll t = 1e18;
		for ( int i=l; i<=r; ++i )
			for ( int j=i+1; j<=r; ++j )
				t = min(t,calc(v[i],v[j]));
		return t;
	}
	int mid = l+r>>1;
	ll ans = min(divide(l,mid),divide(mid+1,r));
	vector<pii> tmp;
	tmp.clear();
	for ( int i=l; i<=r; ++i )
		if ( (v[i].x-v[mid].x)*(v[i].x-v[mid].x) <= ans )
			tmp.emplace_back(v[i]);
	sort(tmp.begin(),tmp.end(),cmpy); // sweep line
	int sz = tmp.size();
	for ( int i=0; i<sz; ++i )
		for ( int j=i+1; j<sz&&j<i+4; ++j )
			ans = min(ans,calc(tmp[i],tmp[j]));
	return ans;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, a, b;
	cin >> n;
	for ( int i=0; i<n; ++i ) {
		cin >> a >> b;
		v.emplace_back(make_pair(a,b));
	}
	sort(v.begin(),v.end());
	cout << divide(0,n-1) << '\n';
	return 0;
}
