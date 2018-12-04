#include <iostream>
#include <vector>
#define maxn 2005
using namespace std;
struct oper {
	int a, b;
};
int arr[maxn];
vector<oper> ans;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for ( int i=1; i<=n; ++i )	cin >> arr[i];
	if ( arr[n] < n ) {
		ans.emplace_back(oper{n,n-arr[n]});
		arr[n] = n;
	}
	int mod = arr[n]+1, tar;
	for ( int i=n-1; i>=1; --i ) {
		for ( oper x : ans )
			arr[i] += x.b;
		if ( arr[i]%mod > i ) {
			tar = (arr[i]/mod+1)*mod+i;
			ans.emplace_back(oper{i,tar-arr[i]});
		} else if ( arr[i]%mod < i ) {
			tar = (arr[i]/mod)*mod+i;
			ans.emplace_back(oper{i,tar-arr[i]});
		}
	}
	cout << ans.size()+1 << '\n';
	for ( oper i : ans )
		cout << 1 << ' ' << i.a << ' ' << i.b << '\n';
	cout << 2 << ' ' << n << ' ' << mod << '\n';
	return 0;
}

