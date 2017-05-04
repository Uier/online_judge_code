#include <iostream>
#include <ctime>
using namespace std;
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	bool a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << !(((a||b)&&(c^d))||((b&&c)^(a||d))) << '\n';
	return 0;
}

