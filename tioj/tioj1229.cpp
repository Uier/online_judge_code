#include <iostream>
#define maxn 105
using namespace std;
int arr[maxn], brr[maxn];
int main() {
	ios::sync_with_stdio(false);
	//   sync_with_YinHsuan(true);
	cin.tie(0);
	int l, n, m;
	cin >> l >> n >> m;
	for ( int i=1; i<=n; ++i )	cin >> arr[i];
	for ( int i=1; i<=n; ++i ) {
		brr[i] = arr[i];
		for ( int j=0; j<m-1; ++j )
			brr[i] = arr[brr[i]];
	}
	string s;
	while ( l-- && cin >> s ) {
		int len = s.size();
		string ans = "";
		for ( int i=0; i<len; ++i )	ans.push_back(' ');
		for ( int i=0; i<len; ++i )	ans[brr[i+1]-1] = s[i];
		cout << ans << '\n';
	}
	return 0;
}

