#include <iostream>
#include <algorithm>
#include <unordered_map>
#define maxn 200005
using namespace std;
struct seg {
	int l, r;
} a[maxn];
bool cmp(seg x, seg y) {
	if ( x.l == y.l )	return x.r > y.r;
	return x.l < y.l
} 
unordered_map<long long,int> M;
long long s[maxn];
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int n;
	cin >> n;
	for ( int i=0; i<n; ++i )
		cin >> a[i].l >> a[i].r;
	sort(a,a+n,cmp);
	
	for ( int i=0; i<n; ++i ) {
		
	}
	return 0;
}

