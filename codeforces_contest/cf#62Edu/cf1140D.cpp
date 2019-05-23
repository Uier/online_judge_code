#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	//   sync_with_YinHsuan(true);
	cin.tie(0);
	int n;
	cin >> n;
	long long sum = 0;
	for ( int i=2; i<n; ++i ) {
		sum += i*(i+1);
	}
	cout << sum << '\n';
	return 0;
}

