#include <iostream>
using namespace std;
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int a, b;
	bool ans = false;
	cin >> a >> b;
	if ( a == 0 && b == 0 )	cout << "NO\n";
	else if ( a == b || a+1 == b || b+1 == a )
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}

