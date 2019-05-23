#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	cout << 3*n+min(n-k,k-1) << '\n';
	return 0;
}
