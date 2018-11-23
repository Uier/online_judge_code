#include <iostream>
#include <vector>
#include <algorithm>
#define maxn 10005
using namespace std;
vector<int> G[maxn], V;
int siz[maxn], conj[maxn], cnt[maxn], n;
void dfs1(int x, int fa) {
	siz[x] = 1;
	for ( int i : G[x] )
		if ( i != fa ) {
			dfs1(i,x);
			siz[x] += siz[i];
			cnt[x] += siz[i]*siz[i];
		}
	cnt[x] += (n-siz[x])*(n-siz[x]);
	// (a + b + c)^2 = a^2 + b^2 + c^2 + 2*(ab + ac + bc)
	conj[x] = ((n*n-n*2+1)-cnt[x])/2;
}
void dfs2(int x, int fa) {
	siz[x] = 1;
	for ( int i : G[x] )
		if ( i != fa ) {
			dfs2(i,x);
			siz[x] += siz[i];
		}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, b;
	cin >> n;
	for ( int i=0; i<n; ++i ) {
		cin >> a >> b;
		G[a].emplace_back(b);
		G[b].emplace_back(a);
	}
	n++;
	dfs1(0,0);
	int m = 0;
	for ( int i=1; i<n; ++i )
		if ( conj[i] > conj[m] )
			m = i;
	dfs2(m,m);
	int sum = 0;
	for ( int i : G[m] ) {
		V.emplace_back(siz[i]);
		sum += siz[i];
	}
	sum *= sum;
	sort(V.begin(),V.end());
	V[V.size()-2] += V[V.size()-1];
	V.pop_back();
	for ( int i : V )
		sum -= i*i;
	sum /= 2;
	cout << conj[m] << ' ' << sum << '\n';
	return 0;
}

