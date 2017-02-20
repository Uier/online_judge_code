#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct doll {
	int W, H;
} a[20005];
bool cmp(doll x, doll y) {
	return ((x.W == y.W) ? (x.H > y.H) : (x.W < y.W));
}
bool lb(doll x, doll y) {
	return (x.H < y.H && x.W < y.W);
}
int lis(int n) {
	if ( n == 0 )	return 0;
	vector<doll> S{a[0]};
	for ( int i=1; i<n; i++ ) {
		doll b = S.back();
		if ( a[i].H > b.H && a[i].W > b.W )
			S.push_back(a[i]);
		else
			*lower_bound(S.begin(),S.end(),a[i],lb) = a[i];
	}
	return S.size();
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t, n;
	cin >> t;
	while ( t-- ) {
		cin >> n;
		for ( int i=0; i<n; i++ )
			cin >> a[i].W >> a[i].H;
		sort(a,a+n,cmp);
		cout << lis(n) << '\n';
	}
	return 0;
}
