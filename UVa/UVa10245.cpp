#include <iostream>
#include <algorithm>
#include <math.h>
#define maxn 10005
using namespace std;
typedef pair<double,double> pdd;
pdd a[maxn], tmp[maxn];
inline double dist(pdd u, pdd v) {
	return	(u.first-v.first)*(u.first-v.first)+(u.second-v.second)*(u.second-v.second);
}
inline bool cmp(pdd u, pdd v) {return u.second < v.second;}
double solve(int l, int r) {
	if ( l >= r )	return 1e18;
	if ( l+1 == r )	return dist(a[l],a[r]);
	if ( l+2 == r ) return min(min(dist(a[l],a[l+1]),dist(a[l+1],a[r])),dist(a[l],a[r]));
	int mid = l+r>>1, p = 0;
	double d = min(solve(l,mid),solve(mid+1,r));
	for ( int i=l; i<=r; ++i )	// scan horizon dist
		if ( (a[mid].first-a[i].first)*(a[mid].first-a[i].first) <= d )
			tmp[p++] = a[i];
	sort(tmp,tmp+p,cmp);
	for ( int i=0; i<p; ++i )
		for ( int j=i+1; j<p; ++j ) {
			if ( (tmp[j].second-tmp[i].second)*(tmp[j].second-tmp[i].second) >= d )
				break;
			d = min(d,dist(tmp[i],tmp[j]));
		}
	return d;
}
int main() {
	int n;
	cin >> n;
	for ( int i=0; i<n; ++i )	scanf("%lf %lf", &a[i].first, &a[i].second);
	sort(a,a+n);
	cout << sqrt(solve(0,n-1)) << '\n';
	return 0;
}
