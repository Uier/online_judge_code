#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#define maxn 105
using namespace std;
vector<int> v, s;
int n, bit[maxn];
void add(int x) {
	for ( int i=x; i<=n; i+=(i&-i) )
		bit[i]++;
}
int sum(int x) {
	int s = 0;
	for ( int i=x; i>0; i-=(i&-i) )
		s += bit[i];
	return s;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	while ( cin >> n ) {
		v.clear();	s.clear();
		memset(bit,0,sizeof(int)*(n+1));
		for ( int i=0, x; i<n; ++i ) {
			cin >> x;
			v.emplace_back(x);
			s.emplace_back(x);
		}
		sort(s.begin(),s.end());
		s.resize(unique(s.begin(),s.end())-s.begin());
		int ans = 0;
		for ( int i=0; i<n; ++i ) {
			int k = lower_bound(s.begin(),s.end(),v[i])-s.begin()+1;
			add(k);
			ans += i-sum(k)+1;
		}
		cout << ans << '\n';
	}
	return 0;
}

