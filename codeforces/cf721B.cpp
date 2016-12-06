#include <iostream>
#include <algorithm>
using namespace std;
int a[105], b[105];
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int n, k, sum=0;
	string s;
	cin >> n >> k;
	for ( int i=0; i<n; i++ ) {
		cin >> s;
		b[i] = s.size();
		a[s.size()]++;
	}
	sort(b,b+n);
	cin >> s;
	for ( int i=1; i<s.size(); i++ )
		sum += a[i];
	int ans = sum + 5*(sum/k) + 1;
	cout << ans << ' ';
	
	ans = 0;
	sum += a[s.size()] - 1;
	ans = sum + 5*(sum/k) + 1;
	cout << ans << '\n';
	return 0;
}

