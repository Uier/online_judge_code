#include <iostream>
#include <algorithm>
#include <vector>
#define maxn 300005
using namespace std;
int son[maxn], put[maxn];
bool p[maxn];
vector<int> G[maxn];
inline bool cmp_min(int x, int y) {
	if ( son[x] == 0 )	return 1;
	if ( son[y] == 0 )	return 0;
	if ( p[x] == p[y] )	return son[x] < son[y];
	return !p[x];
}
inline bool cmp_max(int x, int y) {
	if ( p[x] == p[y] )	return son[x] < son[y];
	return p[x];
}
void dfs(int x, vector<int> val) {
//	cout << "dfs x: " << x << '\n';
	if ( son[x] == 0 ) {
		put[x] = val[0];
		return;
	}
	vector<int> tmp;
	tmp.clear();
	for ( int i : G[x] ) {
		tmp.emplace_back(i);
	}
	if ( p[x] )	sort(tmp.begin(),tmp.end(),cmp_max);
	else	sort(tmp.begin(),tmp.end(),cmp_min);
	vector<int> arg;
	int sum = 0, sz = val.size();
	for ( int i : tmp ) {
		int num = max(1,son[i]);
		sum += num;
		for ( int j=0; j<num; ++j ) {
			arg.emplace_back(val[sz-sum+j]);
		}
		dfs(i,arg);
		arg.clear();
	}
}
void calc(int x) {
//	cout << "cal x: " << x << '\n';
	if ( son[x] == 0 )	return;
	int mx = -1, mn = -1;
	for ( int i : G[x] ) {
		calc(i);
		if ( p[x] ) { // max
			if ( mx == -1 || put[i] > mx )	mx = put[i];
		} else { // min
			if ( mn == -1 || put[i] < mn )	mn = put[i];
		}
	}
	if ( p[x] ) {
		put[x] = mx;
	} else {
		put[x] = mn;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for ( int i=1; i<=n; ++i )	cin >> p[i];
	for ( int i=2, x; i<=n; ++i ) {
		cin >> x;
		G[x].emplace_back(i);
		son[x]++;
	}
	int leaf = 0;
	for ( int i=1; i<=n; ++i )	if ( son[i] == 0 )	leaf++;
	vector<int> val;
	for ( int i=1; i<=leaf; ++i )	val.emplace_back(i);
	dfs(1,val);
	calc(1);
	cout << put[1] << '\n';
	return 0;
}

