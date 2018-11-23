#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	int cnt = k/n;
	if ( k%n )	cnt++;
	cout << cnt << '\n';
	return 0;
}

