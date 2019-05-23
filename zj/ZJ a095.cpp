#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	//   sync_with_YinHsuan(true);
	cin.tie(0);
	int n, m;
	while ( cin >> n >> m ) {
		cout << m+(n!=m) << '\n';
	}
	return 0;
}

