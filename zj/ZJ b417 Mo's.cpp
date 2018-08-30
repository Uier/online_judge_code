#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#define maxn 100005
#define maxm 1000005
using namespace std;
int seq[maxn], cnt[maxn], fre[maxn], ans;
pair<int,int> output[maxm];
struct query {
	int l, r, id;
};
vector<query> M[1005];
inline bool cmp(query a, query b) {return a.r < b.r;}
inline void add(int i) {
	fre[cnt[i]]--;
	cnt[i]++;
	fre[cnt[i]]++;
	ans = max(ans,cnt[i]);
}
inline void rmv(int i) {
	fre[cnt[i]]--;
	cnt[i]--;
	fre[cnt[i]]++;
	if ( fre[ans] == 0 )	ans--;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	int root = sqrt(n);
	if ( root*root < n )	root++;
	for ( int i=1; i<=n; ++i )	cin >> seq[i];
	for ( int i=1, a, b; i<=m; ++i ) {
		cin >> a >> b;
		M[a/root].emplace_back(query{a,b,i});
	}
	for ( int i=0; i<=root; i++ ) {
		if ( M[i].empty() )	continue;
		sort(M[i].begin(),M[i].end(),cmp);
		ans = 0;
		int ptl = M[i][0].l, ptr = M[i][0].l-1;
		for ( query j : M[i] ) {
			while ( ptl < j.l )	rmv(seq[ptl++]);
			while ( ptl > j.l ) add(seq[--ptl]);
			while ( ptr < j.r )	add(seq[++ptr]);
			output[j.id] = make_pair(ans,fre[ans]);
		}
		while ( ptl <= ptr )	rmv(seq[ptl++]); // clear
	}
	for ( int i=1; i<=m; ++i )
		cout << output[i].first << ' ' << output[i].second << '\n';
	return 0;
}

