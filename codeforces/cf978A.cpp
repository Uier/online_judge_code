#include <iostream>
#include <vector>
using namespace std;
bool a[1005];
int b[1005];
vector<int> ans;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for ( int i=0; i<n; ++i )	cin >> b[i];
	for ( int i=0; i<n; ++i ) {
		int x = b[n-1-i];
		if ( a[x] )	continue;
		a[x] = true;
		ans.emplace_back(x);	
	}
	int len = ans.size();
	cout << len << '\n';
	for ( int i=0; i<len; ++i )
		cout << ans[len-1-i] << ' ';
	cout << '\n';
	return 0;
}

