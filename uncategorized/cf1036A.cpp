#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n, k;
	cin >> n >> k;
	long long ans = k/n;
	if ( k%n )	ans++;
	cout << ans << '\n';
	return 0;
}

