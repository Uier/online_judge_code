#include <iostream>
#define maxn 200005
using namespace std;
long long arr[maxn], pre[maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for ( int i=1; i<=n; ++i ) {
		cin >> arr[i];
		pre[i] = pre[i-1] + arr[i];
	}
	for ( int i=1; i<=n; ++i ) {
		long long suf = pre[n]-pre[i-1];
		int pos = lower_bound(pre+1,pre+1+n,suf)-pre;
		if ( pre[pos] == suf && pos < i ) {
			cout << suf << '\n';
			return 0;
		}
	}
	cout << 0 << '\n';
	return 0;
}

