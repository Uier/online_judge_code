#include <iostream>
#include <vector>
#include <algorithm>
#define maxn 200005
using namespace std;
struct pii {
	int par, pos, ni;
};
vector<pii> V;
int tmp[maxn];
bool cmp(pii x, pii y) {
	return x.par < y.par;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int k, n;
	cin >> k;
	for ( int d=1; d<=k; ++d ) {
		cin >> n;
		int sum = 0;
		for ( int i=1; i<=n; ++i ) {
			cin >> tmp[i];
			sum += tmp[i];
		}
		for ( int i=1; i<=n; ++i )
			V.emplace_back(pii{sum-tmp[i],i,d});
	}
	sort(V.begin(),V.end(),cmp);
	int siz = V.size();
	for ( int i=1; i<siz; ++i ) {
		if ( V[i-1].par == V[i].par && V[i-1].ni != V[i].ni ) {
			cout << "YES\n" << V[i-1].ni << ' ' << V[i-1].pos << '\n';
			cout << V[i].ni << ' ' << V[i].pos << '\n';
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}

