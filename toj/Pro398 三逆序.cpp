#include <iostream>
#include <vector>
#include <algorithm>
#define maxn 3000005
using namespace std;
int n, arr[maxn], bit1[maxn];
long long bit2[maxn];
vector<int> rk;
inline void add1(int i) {
	for ( ; i<=n; i+=(i&-i) )	bit1[i]++;
}
inline int sum1(int i) {
	int s = 0;
	for ( ; i>0; i-=(i&-i) )	s += bit1[i];
	return s;
}
inline void add2(int i, int val) {
	for ( ; i<=n; i+=(i&-i) )	bit2[i] += val;
}
inline long long sum2(int i) {
	long long s = 0;
	for ( ; i>0; i-=(i&-i) )	s += bit2[i];
	return s;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for ( int i=1; i<=n; ++i ) {
		cin >> arr[i];
		rk.emplace_back(arr[i]);
	}
	sort(rk.begin(),rk.end());
	rk.resize(unique(rk.begin(),rk.end())-rk.begin());
	long long ans = 0;
	for ( int i=1, x; i<=n; ++i ) {
		x = lower_bound(rk.begin(),rk.end(),arr[i])-rk.begin()+1;
		add1(x);
		ans += sum2(n)-sum2(x-1);
		add2(x,i-1-sum1(x-1));
	}
	cout << ans << '\n';
	return 0;
}

