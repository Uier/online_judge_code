#include <iostream>
#include <algorithm>
using namespace std;
struct seg {
	int l, r;
	bool operator < (seg x) const {
		return l < x.l;
	}
} a[1010];
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int n;
	bool b=true;
	cin >> n;
	int ans=n;
	for ( int i=0; i<n; i++ )
		cin >> a[i].l >> a[i].r;
	sort(a,a+n);
	
	return 0;
}

